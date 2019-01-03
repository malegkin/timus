#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <sstream>


uint64_t process(std::istream &in) {
    uint64_t out = 1;

    uint16_t n, k;
    std::string fk;

    in >> n;
    in >> fk;
    k = fk.size();

    for(;n >= k; n -= k)
        out *= n;

    if (n % k)
        out *= n % k;
   
    return out;
}

uint64_t process(std::string in){
    std::stringstream ss(in);
    return process(ss);
}

int main()
{
    #ifndef ONLINE_JUDGE
        assert(process("9 !!") == 945);
        assert(process("11 !!!") == 880);
        assert(process("9 !!!") == 162);    
        freopen("test.cin", "rt", stdin);
    #endif

    std::cout << process(std::cin) << std::endl;

    return 0;
}
