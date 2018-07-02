#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <string.h>

float Q_rsqrt( double number )
{
	long i;
	float x2, y;
	const double threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck? 
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}


int main()
{    
    char* out = static_cast<char*>(malloc(1024*1024));
    char buf[32];
    size_t out_size = 1024*1024;
    
    std::string line;
    size_t in_size = 0;
    while ( std::getline (std::cin, line) && in_size < 256*1024 ){
        in_size += line.size();
       
        uint64_t in = .0;
        bool is_number = false;
        for(size_t i = 0; i <= line.size(); i++){
            switch(line[i]) {
                case '0' ... '9':
                    in = (in * 10) + static_cast<uint64_t>(line[i] - '0');
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
            }
        }
    }
               
    out[ 1024*1024 ] = '\0';
    
    std::cout << out + out_size;
    free(out);
    
    return 0;
}
