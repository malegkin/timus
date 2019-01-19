#include <iostream>
#include <sstream>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    std::string in;
    std::cin >> in;

    uint32_t d = 5;
    std::transform( std::begin(in), std::end(in), std::begin(in), [&](auto a){
        auto out = 'a' + ((26 + a - 'a') - d) % 26;
        d = a - 'a';
        return out;
    });
    
    std::cout << in ; 
    
    return 0;
}
