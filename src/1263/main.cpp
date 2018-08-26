#include <iostream>
#include <map>
#include <sstream>

int main()
{
    uint32_t N, M;
    std::cin >> N >> M;

/*
    std::map<uint32_t, uint32_t> elections;

    for (uint32_t i = 0; i < M; i++) {

        uint32_t candidate;
        std::cin >> candidate;
        elections[candidate]++;
    }
*/
    uint32_t elections[10000];

    std::fill(elections, elections + N + 1 , 0);

    for (uint32_t i = 0; i < M; i++) {

        uint32_t candidate;
        std::cin >> candidate;
        elections[candidate]++;
    }

    //std::stringstream ss;
    //ss.precision(2);

    for(uint32_t i = 1; i <= N; i++){
        printf("%.2f\%\n", static_cast<float>(100*elections[i])/M);
       //ss << static_cast<float>(100*elections[i])/M << "%" << std::endl;
    }

    //std::cout << ss.str();
    return 0;
}