#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <sstream>


std::string process(std::istream &in) {
    std::string out;
    
    uint16_t n;
    double sum = 0;

    in >> n;

    for (size_t i = 0; i < n; i++){
        uint32_t p;
        in >> p;
        sum += p;
    }

    std::ostringstream oss;
    oss.precision(6);
    oss << std::fixed << sum / n;

    return oss.str();
}

std::string process(std::string in){
    std::stringstream ss(in);
    return process(ss);
}

int main()
{
    #ifndef ONLINE_JUDGE
        assert(process("3 7 4 5") == "5.333333");
        
        freopen("test.cin", "rt", stdin);
    #endif

    std::cout << process(std::cin) << std::endl;

    return 0;
}
