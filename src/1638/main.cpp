#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <sstream>

std::string linetos(std::istream& in ){
    std::string line;
    getline(in, line);
    return line;
}

std::string process(std::istream &in) {
    uint16_t a,b,c,d;
    in >> a >> b >> c >> d;

    if (c < d)
        return std::to_string( (d - c)*(a + 2*b) - a );

    return std::to_string( (c - d)*(a + 2*b) + a );
}

std::string process(std::string in){
    std::stringstream ss(in);
    return process(ss);
}

int main()
{
    #ifndef ONLINE_JUDGE
        assert(process("10 1 2 1") == "22");

        freopen("test.cin", "rt", stdin);
    #endif

    std::cout << process(std::cin) << std::endl;

    return 0;
}
