#include <iostream>
#include <string>
#include <cassert>

// there is no solution for n>2 :)
// http://en.wikipedia.org/wiki/Fermat%27s_Last_Theorem


std::string process(const uint32_t N){
    std::string out;

    switch(N){
        case 1:
            out = "1 2 3";
            break;
        case 2:
            out = "3 4 5";
            break;
        
        default:
            out = "-1";

    }

    return out;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.cin", "rt", stdin);

        assert(process(0) == "-1");
        assert(process(1) == "1 2 3");
    #endif

    uint32_t N;
    std::cin >> N;

    std::cout << process(N) << std::endl;

    return 0;
}
