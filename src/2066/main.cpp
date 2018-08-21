#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    std::array<int32_t, 3> in;
    std::cin >> in[0] >> in[1] >> in[2];
    
    std::sort( std::begin(in), std::end(in) );
    
    int32_t in_max_mult = in[2]*in[1];
    int32_t in_max_add = in[2]+in[1];
    
    std::cout << in[0] - ( in_max_add > in_max_mult ? in_max_add : in_max_mult ) << std::endl;
        
    
   return 0;
}
