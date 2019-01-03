#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <sstream>


std::string process(std::istream &in) {
    std::string out;

    uint32_t x,y,c;
    in >> x >> y >> c;
    
    if (x+y < c)
        return "Impossible";

    std::ostringstream oss;
    oss << std::min(x,c) << " " << c - std::min(x,c);
    return oss.str();
}

std::string process(std::string in){
    std::stringstream ss(in);
    return process(ss);
}

int main()
{
    #ifndef ONLINE_JUDGE
        assert(process("2 7 5") == "2 3");
        assert(process("9 15 100") == "Impossible");
        
        freopen("test.cin", "rt", stdin);
    #endif

    std::cout << process(std::cin) << std::endl;

    return 0;
}
