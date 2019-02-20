#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <functional>

template <typename T>
struct matrix_t {
        matrix_t (size_t height, size_t width)
            : _height(height)
            , _width(width){};

        void init(std::istream &in) {
            _data.reserve( _height*_width );
            std::copy_n( std::istream_iterator<T>(in), _height*_width, std::back_insert_iterator<std::vector<T>>( _data ));
        }

        auto operator[](size_t i) const {
            return std::begin( _data ) + i*_width;
        }

        inline size_t get_height() const {
            return _height;
        }

        inline size_t get_width() const {
            return _width;
        }
    
    private:
        std::vector<T> _data;
        size_t _height;
        size_t _width;
};

// Implementation of Kadane's algorithm for 1D array. 
// The function returns maximum sum subarray tuple with:
//  - sum
//  - starting index
//  - ending index  

template <typename T>
auto get_maximal_sub_array(const std::vector<T>& in) {
 
    T global_max  = std::numeric_limits< T >::min();
    T local_max   = 0;

    size_t  i_start     = 0;
    size_t  i_end       = 0;
    size_t  i_local_s   = 0; 
  
    for (size_t i = 0; i < in.size(); i++) {

        local_max += in[i]; 
  
        if ( global_max < local_max ) { 
            global_max = local_max; 
            i_start = i_local_s; 
            i_end   = i; 
        } 
  
        if ( local_max < 0 ) { 
            local_max = 0; 
            i_local_s = i + 1; 
        } 
    }
    
    return std::make_tuple( global_max, i_start, i_end );
} 

template <typename T>
auto get_maximal_sub_rectangle(const matrix_t<T>& in) {
    T gm = std::numeric_limits<T>::min();
    std::vector<T> tmp(in.get_height(), 0);
 
    for (size_t i_left = 0; i_left < in.get_width(); ++i_left){
        std::fill( std::begin(tmp), std::end(tmp), 0);
        for (size_t i_right = i_left; i_right < in.get_width(); ++i_right){
            for (size_t i = 0; i < in.get_height(); i++)
                tmp[i] += in[i][i_right];
            
            auto msa = get_maximal_sub_array(tmp);
            gm = std::max(gm, std::get<0>(msa));
        }
    }

    return gm; 
}


int main()  {
    
    uint32_t n;
    std::cin >> n;
    matrix_t< int32_t > in(n, n);
    in.init( std::cin ); 
    
    std::cout << get_maximal_sub_rectangle(in);

    return 0;
}
