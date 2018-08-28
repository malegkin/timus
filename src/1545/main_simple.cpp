#include<iostream>
#include<string>
#include<map>
#include<set>


int main(){

    std::map<char, std::set<std::string>> hieroglyphs;
    std::string line;
    uint32_t    n;

    std::cin >> n;
    while(n--) {
        std::cin >> line;
        hieroglyphs[line[0]].insert(line);
    }

    std::cin >> line;

    for(auto s: hieroglyphs[line[0]])
        std::cout << s << std::endl;
}