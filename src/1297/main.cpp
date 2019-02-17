#include <iostream>
#include <sstream>
#include <cassert>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>


template <typename Iterator> 
bool is_palindrome( Iterator it_begin, Iterator it_end ){
    while ( it_begin < it_end )
        if ( *(it_begin++) != *(it_end--) )
            return false;

    return true; 
}
/*
bool is_palindrome( const std::string& in ) {
    return is_palindrome( std::begin(in), --std::end(in) );
}
*/


int main()
{
/*
    assert( is_palindrome( "abba" ));
    assert( is_palindrome( "aba" ));
    assert( is_palindrome( "a" ));

    //negative cases
    assert( !is_palindrome( "abcrba" ));
*/
    std::string in;
    std::cin >> in;
    
    //std::multimap< std::string::value_type, std::string::const_reverse_iterator > char_index;
    std::multimap< char, std::string::const_iterator > char_index;
    //получить итератор?
    for (auto it = std::cbegin(in); it < std::cend(in); ++it) {
        char_index.insert( std::make_pair(*it, it) );
    } 

    std::string max_palindrome = "";
    try{   
    for (auto it_begin = std::cbegin(in); it_begin < std::cend(in); ++it_begin) {
        auto ends = char_index.equal_range( *it_begin );
        for (auto it = ends.first; it != ends.second; ++it) {
            auto it_end = it->second;
            std::cout << std::distance(it_begin, it_end) << std::endl;
            if ( max_palindrome.size() < std::distance(it_begin, it_end) 
                && is_palindrome(it_begin, it_end)) {
                max_palindrome = std::string( it_begin , it_end );
            }
        }
    }
} catch (const std::exception& e) { // reference to the base of a polymorphic object
     std::cout << "ERROR: " << e.what(); // information from length_error printed
    return -1;
}


    std::cout << max_palindrome << std::endl;   
 
    return 0;
}
