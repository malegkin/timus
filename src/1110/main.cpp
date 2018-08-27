#include <iostream>
#include <string>
#include <cassert>

//if a ≡ b (mod n), then:
//a^k ≡ b^k (mod n) for any non-negative integer k (compatibility with exponentiation)
//k*a ≡ k*b (mod n) for any integer k (compatibility with scaling)

uint32_t get_xn_mod_m(uint32_t x, uint32_t n, uint32_t m){
    uint32_t out = 1;
    for (uint32_t i = 0; i < n; i++){
        out *= x;
        out %= m;
    }

    return out;
}

std::string process(const uint32_t N, const uint32_t M, const uint32_t Y){
    std::string out = "-1";

    for(uint32_t x = 0; x < M; x++){
        if (get_xn_mod_m(x, N, M) == Y){
            if (out == "-1")
                out = std::to_string(x);
            else out += " " + std::to_string(x);
        }
    }
    
    return out;
}

int main()
{
    #ifndef ONLINE_JUDGE
        assert(get_xn_mod_m(2, 8, 3) == 1);
        assert(get_xn_mod_m(555, 555, 111) == 0);

        freopen("test.cin", "rt", stdin);
        assert(process(2, 6, 4) == "2 4");
        assert(process(2, 1, 5) == "-1");
    #endif

    uint32_t N, M, Y ;
    std::cin >> N >> M >> Y;

    std::cout << process(N, M, Y) << std::endl;

    return 0;
}
