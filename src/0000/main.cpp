#include <iostream>
#include <string>
#include <cassert>

std::string process(const std::string& in){
    std::string out;

    return out;
}

std::string process(const uint32_t N){
    std::string out;

    return out;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.cin", "rt", stdin);

        std::string test_in = "";
        std::string test_out = "";
        assert(process(test_in) == test_out);
    #endif

    uint32_t N;
    std::cin >> N;

    std::cout << process(N) << std::endl;

    return 0;
}
