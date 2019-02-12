#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <iterator>

static const size_t SQUARE_DIMENSION = 4;
using square_t = std::array<std::string, SQUARE_DIMENSION>;

template <typename F>
void repeat(unsigned n, F f) {
    while (n--) f();
}

inline square_t read_square(std::istream &in){
    square_t out;
    
    std::generate_n( std::begin(out), SQUARE_DIMENSION, [&](){
        std::string line;
        getline(in, line);
        return std::move( line ); 
    });

    return std::move( out );
}

inline square_t& rotate(square_t& in){

    for (size_t i = 0; i < SQUARE_DIMENSION; i++) {
        for (size_t j = i; j < SQUARE_DIMENSION; j++) {
            std::swap( in[i][j], in[j][i] ); 
        }
    }


    for(size_t i = 0; i < SQUARE_DIMENSION/2; i++) {
        for(size_t j = 0; j < SQUARE_DIMENSION; j++) {
            std::swap( in[j][i], in[j][SQUARE_DIMENSION - i - 1] );
        }
    }
    
    return in;
}


inline std::string merge(const square_t& ciphered, const square_t& grille){
    std::string out;

    for (size_t i = 0; i < SQUARE_DIMENSION; i++){
        for (size_t j = 0; j < SQUARE_DIMENSION; j++){
            if ( grille[i][j] == 'X' )
                out += ciphered[i][j];
        }
    }
    

    return std::move( out );
}


int main()
{
    auto grille     = read_square( std::cin );
    auto ciphered   = read_square( std::cin );


    repeat(4, [&](){
        std::cout << merge( ciphered, grille);
        rotate(grille);
    });

    return 0;
}
