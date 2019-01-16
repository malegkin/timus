#include <iostream>
#include <sstream>
#include <iterator>
#include <cassert>
#include <string>
#include <algorithm>
#include <array>
#include <map>

template < class T, size_t ROWS_COUNT, size_t COLUMNS_COUNT>
using matrix = std::array<std::array<T, COLUMNS_COUNT>, ROWS_COUNT>;

std::string solve(std::istream &in) {
    matrix<size_t, 6, 6> ds;
    for( size_t i = 1; i <= 5; i++ ){
        for( size_t j = 1; j <= 5; j++ ){
            in >> ds[i][j];
        }
    } 

    std::map<size_t, std::array<size_t, 3>> paths;
    std::array<size_t, 3> ps = {2, 3, 4};
    do{
        //Moreover, Ilya doesn’t want to be the last student to get home, so point 3 can’t be fourth in the path.
        if ( ps[2] == 3 ) 
            continue;
        
        size_t path_lenght = ds[1][ps[0]] + ds[ps[0]][ps[1]] + ds[ps[1]][ps[2]] + ds[ps[2]][5];
        paths[path_lenght] = ps;

    } while(std::next_permutation( std::begin(ps), std::end(ps) ));
    
    auto optimal_path = *std::begin(paths);

    std::stringstream out;
    out << optimal_path.first <<  std::endl << "1 ";
    std::copy( std::begin(optimal_path.second), std::end(optimal_path.second), std::ostream_iterator<size_t>(out, " "));
    out << "5" << std::endl;
    
    return out.str();
}

std::string solve(std::string in){
    std::stringstream ss(in);
    return solve(ss);
}

int main()
{
    std::cout << solve( std::cin ) << std::endl;

    return 0;
}
