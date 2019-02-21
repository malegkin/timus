#include <iostream>
#include <sstream>
#include <cassert>
#include <string>
#include <algorithm>
#include <set>

int main()
{
    size_t n;
    std::cin >> n;
    std::cin.get();

    std::set< std::string > in;

    std::generate_n( std::inserter( in, std::begin( in )), n, []{
        std::string out;
        std::getline( std::cin, out );
        return out; 
    });
    
    std::cout << n - in.size() << std::endl;

    return 0;
}
