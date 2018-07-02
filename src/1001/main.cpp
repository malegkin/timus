#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>

int main()
{    
    char* out = static_cast<char*>(malloc(1024*1024));
    char buf[32];
    size_t out_size = 1024*1024;
    
    char inpt[256*1024];
    size_t indx = 0;
    indx = fread(inpt, 1, 256*1024, stdin);
    
    uint64_t in = 0;
    bool is_number = false;
    for(size_t i = 0; i <= indx; i++) 
    {  
        switch(inpt[i]) {
            case '0' ... '9':
                in = (in * 10) + static_cast<uint64_t>(inpt[i] - '0');    
                is_number = true;
            break;
                
            default:
                if (is_number){
                    size_t n = sprintf( buf, "%.4f\n", sqrt( in ));
                    buf[n] = '\n';
                    out_size -= n;
                    memcpy(out + out_size, buf, n);
                    is_number = false;
                    in = 0;
                    
                }
            break;
        }
    }
               
    out[ 1024*1024 ] = '\0';
    
    std::cout << out + out_size;
    
    return 0;
}
