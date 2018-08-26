//0.43s	3 976 KB
//150K
//real	0m2.386s
//user	0m1.093s
//sys	0m1.261s

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("t150k.cin", "rt", stdin);
    #endif

    uint32_t N;
    std::cin >> N ;

    std::array<std::vector<std::string>, 101> in;

    while (N--){
        std::string id;
        uint32_t m;
        std::cin >> id >> m;
        
        in[m].push_back(id);
    }

    for(int32_t u = 100; u >= 0; u--){
        std::string us = std::to_string(u);
        for(auto& a: in[u]){
            std::cout << a << " " << us << std::endl;
        }
    }

    return 0;
}   
