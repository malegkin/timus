#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>
#include <sstream>

uint16_t process(std::istream &in) {
    uint16_t k, out = 0;
    in >> k;
    
    std::vector<uint16_t> ks;
    std::generate_n( std::back_inserter(ks), k, [&]() {
        uint16_t t;
        in >> t;
        return t;
    });

    std::sort(std::begin(ks), std::end(ks));

    for(size_t i = 0; i <= k/2; i++){
        out += ks[i]/2 + 1;
    }

    return out;
}

uint16_t process(std::string in){
    std::stringstream ss(in);
    return process(ss);
}

int main()
{
    #ifndef ONLINE_JUDGE
        assert(process("3 5 5 7") == 6);
        assert(process("1 1") == 1);
        
        freopen("test.cin", "rt", stdin);
    #endif

    std::cout << process(std::cin) << std::endl;

    return 0;
}
