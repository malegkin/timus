#include <iostream>
#include <sstream>
#include <cassert>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <iterator>

int main()
{
    uint32_t n;
    (std::cin >> n).get();
    std::map<std::string, std::stringstream> hogwarts;

    while( n-- ) {
        std::string house, name;
        std::getline( std::cin, name );
        std::getline( std::cin, house );
        hogwarts[ house ] <<  name << std::endl;
    } 

    for (auto house: {"Slytherin", "Hufflepuff", "Gryffindor", "Ravenclaw"}) {
        std::cout << house << ":" << std::endl;
        std::cout << hogwarts[house].str() << std::endl;  
    }

    return 0;
}
