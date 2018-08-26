#include <iostream>
#include <string>
#include <map>
#include <algorithm>

std::string process(uint32_t N){
    std::map<std::string, uint32_t> penguins;

    std::string line;
    getline(std::cin, line);    
    while(N--){
        getline(std::cin, line);
        penguins[line]++;
    }
    
   return (*std::max_element(begin(penguins), end(penguins), [](auto p1, auto p2){
        return p1.second < p2.second;
    } )).first;
}

int main()
{
    uint32_t N;
    std::cin >> N;


    std::cout << process(N) << std::endl;

    return 0;
}