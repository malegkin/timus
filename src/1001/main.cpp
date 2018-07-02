#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <string.h>


int main()
{    
    char* out = static_cast<char*>(malloc(1024*1024));
    char buf[32];
    size_t out_size = 1024*1024;
    
    uint64_t in;
    for(int i = 0; i < 256*1000 && std::cin >> in; i++)
    {
        size_t n = sprintf( buf, "%.4f\n", sqrt( static_cast<double>( in )));
        buf[n] = '\n';
        out_size -= n;
        memcpy(out + out_size, buf, n);
    }
    
    out[ 1024*1024 ] = '\0';
    
    std::cout << out + out_size;
    
    return 0;
}
