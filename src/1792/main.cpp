#include <iostream>
#include <sstream>
#include <iterator>
#include <cassert>
#include <string>
#include <algorithm>
#include <array>

std::string solve(std::istream &in) {
    std::array<bool, 7> ina;
    for(size_t i = 0; i < 7; i++){
        in >> ina[i];
    }

    bool r1 = ina[1] xor ina[2] xor ina[3];
    bool r2 = ina[0] xor ina[2] xor ina[3];
    bool r3 = ina[0] xor ina[1] xor ina[3];

    if ( r1 == ina[4] && r2 != ina[5] && r3 != ina[6])  ina[0] = !ina[0];  
    if ( r1 != ina[4] && r2 == ina[5] && r3 != ina[6])  ina[1] = !ina[1];  
    if ( r1 != ina[4] && r2 != ina[5] && r3 == ina[6])  ina[2] = !ina[2];  
    if ( r1 != ina[4] && r2 != ina[5] && r3 != ina[6])  ina[3] = !ina[3];  

    if ( r1 != ina[4] && r2 == ina[5] && r3 == ina[6])  ina[4] = !ina[4];  
    if ( r1 == ina[4] && r2 != ina[5] && r3 == ina[6])  ina[5] = !ina[5];  
    if ( r1 == ina[4] && r2 == ina[5] && r3 != ina[6])  ina[6] = !ina[6];  
    

    std::stringstream out;
    std::copy(std::begin(ina), std::end(ina), std::ostream_iterator<bool>(out, " "));
    return out.str();
}

std::string solve(std::string in){
    std::stringstream ss(in);
    return solve(ss);
}

int main()
{
    assert( solve("1 1 1 0 0 0 1") == "1 1 1 0 0 0 0 " );
    assert( solve("1 0 1 0 0 0 0") == "1 1 1 0 0 0 0 " );
    assert( solve("1 1 0 0 0 0 0") == "1 1 1 0 0 0 0 " );
    assert( solve("1 1 1 1 0 0 0") == "1 1 1 0 0 0 0 " );
    assert( solve("1 1 1 0 1 0 0") == "1 1 1 0 0 0 0 " );
    assert( solve("1 1 1 0 0 1 0") == "1 1 1 0 0 0 0 " );
    assert( solve("0 1 1 0 0 0 0") == "1 1 1 0 0 0 0 " );


    std::cout << solve( std::cin ) << std::endl;

    return 0;
}
