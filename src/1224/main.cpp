#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <cmath>

uint32_t process(std::istream &in) {
    uint32_t n,m;
    in >> n >> m;

    return (n > m)?(m*2 - 1):(n*2 - 2);
}

uint32_t process(std::string in){
    std::stringstream ss(in);
    return process(ss);
}

int main()
{
    #ifndef ONLINE_JUDGE
        assert(process("1 5") == 0);
        assert(process("2 5") == 2);
        assert(process("3 5") == 4);
        assert(process("3 3") == 4);
        assert(process("5 3") == 5);
        
        freopen("test.cin", "rt", stdin);
    #endif

    std::cout << process(std::cin) << std::endl;

    return 0;
}
