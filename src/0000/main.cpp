#include <iostream>
#include <sstream>
#include <cassert>
#include <string>
#include <algorithm>

std::string solve(std::istream &in) {
    std::string out;


    return out;
}

std::string solve(std::string in){
    std::stringstream ss(in);
    return solve(ss);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("./tests/1.in", "rt", stdin);
    #endif

    std::cout << solve( std::cin ) << std::endl;

    return 0;
}
