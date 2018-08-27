#include <iostream>
#include <string>
#include <cassert>

//https://en.wikipedia.org/wiki/Divisibility_rule#Divisibility_by_7
    //Using quick alternating additions and subtractions:
    //  42,341,530 -> 530 − 341 + 42 = 189 + 42 = 231 -> 23 − (1×2) = 21  YES

int32_t to_equl_3d_sum(const std::string& in){
    int32_t out    = 0;

    uint32_t digit  = 1;
    uint32_t sum3d  = 0;
    int32_t  sign   = 1;

    for (uint8_t i = 0; i < in.size(); i++){
        uint8_t c = in[in.length() - 1 - i];

        sum3d += digit * (c - '0');
        digit *= 10;

        if (digit == 1000){
            out     +=  sign * sum3d;
            sign    *=  -1;
            sum3d   =   0;
            digit   =   1;
        }
    }

    out += sign * sum3d;

    //std::cout << in << " ~ " << out << std::endl;

    return out;
}

std::string process(const std::string& in){
    int32_t out = to_equl_3d_sum(in) % 7;
    if (out < 0)
        out += 7 ;

    return std::to_string(out);
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.cin", "rt", stdin);

        assert(to_equl_3d_sum("0") == 0);
        assert(to_equl_3d_sum("555") == 555);
        assert(to_equl_3d_sum("42341530") == 231);
        assert(to_equl_3d_sum("555111") == -444);

        assert(process("12345678901234567890123456789012345678901234567890") == "1");

        std::string test_in     = "123456123456";
        std::string test_out    = "1";
        assert(process(test_in) == test_out);
    #endif

    std::string in;
    std::cin >> in;

    std::cout << process(in) << std::endl;

    return 0;
}
