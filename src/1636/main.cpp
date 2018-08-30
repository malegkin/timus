#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <sstream>

int linetoi(std::istream& in ){
    std::string line;
    getline(in, line);
    return std::stoi(line);
}

std::string linetos(std::istream& in ){
    std::string line;
    getline(in, line);
    return line;
}

std::string process(std::istream &in) {
    std::string out;


    return out;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.cin", "rt", stdin);

        std::stringstream ss(
"\n\
\n");
        assert(process(ss) == "");


        assert(process(std::cin) == "");
        return 0;
    #endif

    std::cout << process(std::cin) << std::endl;

    return 0;
}
