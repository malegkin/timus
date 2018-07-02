#include <iostream>
#include <cmath>

const size_t OUT_BUFFER_SIZE    = 1024*1024;
const size_t INPUT_BUFFER_SIZE  = 256*1024;

int main()
{    
    char    out_buffer[OUT_BUFFER_SIZE];
    size_t  out_buffer_index    =  OUT_BUFFER_SIZE;
    
    char    in_buffer[INPUT_BUFFER_SIZE];
    size_t  in_buffer_index     = 0;
    in_buffer_index             = fread(in_buffer, 1, INPUT_BUFFER_SIZE, stdin);
    

    uint64_t in = 0;
    bool is_number = false;
    for(size_t i = 0; i <= in_buffer_index; i++) 
    {  
        switch(in_buffer[i]) {
            case '0' ... '9':
                in = (in * 10) + static_cast<uint64_t>(in_buffer[i] - '0');    
                is_number = true;
            break;
                
            default:
                if (is_number){
                    double sd = sqrt ( in ); 

                    uint32_t sd_integer     = static_cast<uint32_t>(sd);
                    uint32_t sd_fractional  = static_cast<uint32_t>((sd - sd_integer)*10000);
           
                    out_buffer[--out_buffer_index] = '0' + (sd_fractional % 10);
                    out_buffer[--out_buffer_index] = '0' + (sd_fractional % 100)/10;
                    out_buffer[--out_buffer_index] = '0' + (sd_fractional % 1000)/100;
                    out_buffer[--out_buffer_index] = '0' + (sd_fractional % 10000)/1000;
                    out_buffer[--out_buffer_index] = '.';
                    
                    do {
                        out_buffer[--out_buffer_index] = '0' + sd_integer % 10;
                        sd_integer /= 10;       
                    } while ( sd_integer > 0 );

                    out_buffer[--out_buffer_index] = '\n';

                    is_number = false;
                    in = 0;
                }
            break;
        }
    }
               
    out_buffer[ OUT_BUFFER_SIZE ] = '\0';
    
    puts(out_buffer + out_buffer_index);
    
    return 0;
}