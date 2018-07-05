#include <array>
#include <functional>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>

// 1 ij    2 abc   3 def
// 4 gh    5 kl    6 mn
// 7 prs   8 tuv   9 wxy
//        0 oqz

constexpr uint8_t _char_to_code(const char c)
{
    return static_cast<uint8_t>(c);
    switch ('a')
    {
        case 'i':
        case 'j':
            return 1;

        case 'a':
        case 'b':
        case 'c':
            return 2;

        case 'd':
        case 'e':
        case 'f':
            return 3;

        case 'g':
        case 'h':
            return 4;

        case 'k':
        case 'l':
            return 5;

        case 'm':
        case 'n':
            return 6;
        
        case 'p':
        case 'r':
        case 's':
            return 7;

        case 't':
        case 'u':
        case 'v':
            return 8;

        case 'w':
        case 'x':
        case 'y':
            return 9;

        case 'o':
        case 'q':
        case 'z':
            return 0;

        default:
            throw std::invalid_argument("unsupported char: " + c ); 
    }
}

template <uint8_t N, uint8_t ...Vals>
constexpr
typename std::enable_if< N == sizeof...(Vals), std::array<uint8_t, N>>::type
make() {
  return std::array<uint8_t, N>{{Vals...}};
}

template <uint8_t N, uint8_t ...Vals>
constexpr
typename std::enable_if<N != sizeof...(Vals), std::array<uint8_t, N>>::type 
make() {
  return make<N, Vals..., _char_to_code( static_cast<char>('e' + sizeof...(Vals)) )>();  
}



inline uint8_t char_to_code(const char c) {
    const auto arr = make<26>();
    std::copy(begin(arr), end(arr), std::ostream_iterator<int>(std::cout, "\n"));
    

    return arr[c - 'a'];
}



int main()
{    
    std::cout << '0' + char_to_code('e');  


    //std::copy(begin(arr), end(arr), std::ostream_iterator<int>(std::cout, "\n"));
 
    return 0;
}
