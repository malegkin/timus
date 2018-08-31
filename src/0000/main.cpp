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

std::string process(std::string in){
    std::stringstream ss(in);
    return process(ss);
}

int main()
{
    #ifndef ONLINE_JUDGE
        assert(process("") == "");
        
        freopen("test.cin", "rt", stdin);
    #endif

    std::cout << process(std::cin) << std::endl;

    return 0;
}
