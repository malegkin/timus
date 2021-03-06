//0.514s	2'724 KB
//150k.cin
//real	0m2.746s
//user	0m1.423s
//sys	0m1.309s


#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("t150k.cin", "rt", stdin);
    #endif

    uint32_t N;
    std::cin >> N ;

    std::vector<std::tuple<uint32_t, uint32_t>> in;

    while (N--){
        uint32_t id, m;
        std::cin >> id >> m;
        in.push_back(std::make_tuple(id, m));
    }

    std::stable_sort(begin(in), end(in), [](auto t1, auto t2){
        return std::get<1>(t1) > std::get<1>(t2);
    });

    for(auto a: in){
        std::cout << std::get<0>(a) << " " << std::get<1>(a) << std::endl;
    }

    return 0;
} 