#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

std::string process(const std::string& in){
    std::stringstream ss(in);

    uint32_t a, b, c,d;
    ss >> a >> b >> c >> d;

    //taxi drivers price less peter' price
    if (c < a){
        return std::to_string(a);
    }
    
    uint32_t n  = (c - a) / (b + d);
    uint32_t f =  (c - a) % (b + d);

    // if f > b (accept last full Petr's price) || (accept last full taxi driver price)
    if (f == 0)
        return std::to_string(a + b*n);

    uint32_t amount = ( f > b ? a + b * (n + 1)  : c - d * n  );    

    //std::cout << in << " - " << f <<":"<< n << " " << amount << std::endl; 
    return std::to_string(amount);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.cin", "rt", stdin);

        std::string test_in = "";
        std::string test_out = "";        
        assert(process("150 50 1000 100") == "450");
        assert(process("100 50 200 50") == "150"); 
        assert(process("100 10 200 50") == "120"); // last step taxi driver (acceptr Petrs price)
        assert(process("100 50 200 10") == "190"); // last step Petr (accept taxi drivers price)
        assert(process("200 50 100 10") == "200"); ////taxi drivers price less peter' price

        assert(process("100 100 150 20") == "150");
        assert(process("100 100 50 20") == "100");

    #endif

    std::string in;
    getline(std::cin, in);

    std::cout << process(in) << std::endl;

    return 0;
}
