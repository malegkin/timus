#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <iterator>

constexpr size_t TIMUS_1712_SQUARE_DIMENSION = 4;
using square_t = std::array<std::string, TIMUS_1712_SQUARE_DIMENSION>;

template <typename F>
void repeat(unsigned n, F&& f) {
    while (n--) f();
}

inline square_t read_square(std::istream &in){
    square_t out;
    
    std::generate( std::begin(out), std::end(out), [&](){
        std::string line;
        line.reserve( TIMUS_1712_SQUARE_DIMENSION );
        getline(in, line);
        return line; 
    });

    return out;
}

inline void rotate(square_t& in){

    for (size_t i = 0; i < TIMUS_1712_SQUARE_DIMENSION; i++) {
        for (size_t j = i; j < TIMUS_1712_SQUARE_DIMENSION; j++) {
            std::swap( in[i][j], in[j][i] ); 
        }
    }


    for(size_t i = 0; i < TIMUS_1712_SQUARE_DIMENSION/2; i++) {
        for(size_t j = 0; j < TIMUS_1712_SQUARE_DIMENSION; j++) {
            std::swap( in[j][i], in[j][TIMUS_1712_SQUARE_DIMENSION - i - 1] );
        }
    }
}


inline std::string merge(const square_t& ciphered, const square_t& grille){
    std::string out;
    out.reserve( TIMUS_1712_SQUARE_DIMENSION*TIMUS_1712_SQUARE_DIMENSION );

    for (size_t i = 0; i < TIMUS_1712_SQUARE_DIMENSION; i++){
        for (size_t j = 0; j < TIMUS_1712_SQUARE_DIMENSION; j++){
            if ( grille[i][j] == 'X' )
                out += ciphered[i][j];
        }
    }
    

    return out;
}


int main()
{
    auto grille     = read_square( std::cin );
    auto ciphered   = read_square( std::cin );


    repeat(4, [&](){
        std::cout << merge( ciphered, grille );
        rotate( grille );
    });

    return 0;
}
