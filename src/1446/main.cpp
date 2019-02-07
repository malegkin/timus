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
    std::map<std::string, std::vector<std::string>> hogwarts;
    

    while( n-- ) {
        std::string house, name;
        std::getline( std::cin, name );
        std::getline( std::cin, house );
        hogwarts[ house ].push_back( name );
    } 

    for (auto house: {"Slytherin", "Hufflepuff", "Gryffindor", "Ravenclaw"}) {
        std::cout << house << ":" << std::endl;
        auto students = hogwarts[house];
        std::copy( std::begin( students ), std::end( students ), 
                    std::ostream_iterator< std::string >( std::cout, "\n" ));
        std::cout << std::endl;  
    }

    return 0;
}
