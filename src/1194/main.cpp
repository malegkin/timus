#include <iostream>
#include <sstream>
#include <cassert>
#include <string>
#include <algorithm>

std::string solve(std::istream &in) {
    uint32_t n, k;
    in >> n >> k;
    
    uint32_t out = (n*(n-1)/2) - k;

    return std::to_string(out);
}


int main()
{
    std::cout << solve( std::cin ) << std::endl;

    return 0;
}
