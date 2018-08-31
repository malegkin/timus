#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <array>

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
    auto us = linetos(in); // universal_spell
    std::array<char, 26> acc; //array char counters

    std::fill(begin(acc), end(acc), 0);

    for (auto c: us){
        acc[c - 'a']++;
    }
    


    out += 'a' + (std::max_element(begin(acc), end(acc)) - begin(acc));

    return out;
}

std::string process(std::string in){
    std::stringstream ss(in);
    return process(ss);
}

int main()
{
    #ifndef ONLINE_JUDGE
        assert(process("tebidohtebidoh") == "b");
        
        freopen("test.cin", "rt", stdin);
    #endif

    std::cout << process(std::cin) << std::endl;

    return 0;
}
