#include <iostream>
#include <string>
#include <cassert>

uint32_t get_digit_sum(const uint32_t n){
    uint32_t out = 0;
    std::string sn = std::to_string(n);    
    for(char c: sn){
        out += c - '0';
    }
    return out; 
}

std::string process(const uint32_t N){
    std::string out;

    uint32_t hi,lo;

    hi = N / 1000;
    lo = N % 1000;

    if (get_digit_sum(hi) == get_digit_sum(lo + 1) || get_digit_sum(hi) == get_digit_sum(lo -1))
        return "Yes";


    return "No";
}

int main()
{
    #ifndef ONLINE_JUDGE
        assert(get_digit_sum(123) == 6);
        assert(get_digit_sum(555) == 15);
        assert(process(129130) == "Yes");
        assert(process(129120) == "No");

        freopen("test.cin", "rt", stdin);
    #endif

    uint32_t N;
    std::cin >> N;

    std::cout << process(N) << std::endl;

    return 0;
}
