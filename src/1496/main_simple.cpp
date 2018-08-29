#include <iostream>
#include <map>
#include <string>

int main(){

    std::string line;
    std::map<std::string, uint32_t> m;

    while (getline(std::cin, line))
        m[line]++;

    for(auto a: m)
        if (a.second > 1)
            std::cout << a.first << std::endl;
 
    return 0;
}