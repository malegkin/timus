#include <iostream>
#include <sstream>
#include <iterator>
#include <set>


inline uint32_t get_i(std::istream &in){
    uint32_t out;
    in >> out;
    return out;
}

std::string solve(std::istream &in) {
    
    uint32_t n;
    std::multiset< uint32_t, std::greater<uint32_t> > arr;

    in >> n;

    while(n--) {
        arr.insert( get_i( in ) );        
    }
    
    std::stringstream ss;
    std::copy( std::begin(arr), std::end(arr), std::ostream_iterator<uint32_t>(ss, "\n"));

    return ss.str();
}

int main()
{
    std::cout << solve( std::cin ) << std::endl;

    return 0;
}
