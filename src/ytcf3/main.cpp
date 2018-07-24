#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

int main()
{    
    uint32_t N;
    
    std::cin >> N;

    uint32_t taxis[300][2];


    for (int i = 0; i < N; i++){
        std::cin >> taxis[i][0] >> taxis[i][1];
    }

    uint32_t routes[300][300];
    


    std::vector<int64_t> v;
    v.reserve(m+1);
    for (int i =0; i <= m; i++){
        v[i] = 0;
    }

    for (int i = 0; i < n-1; i++){
        char id[10];
        uint32_t d, c;
        scanf("%10s%d%d", id, &d, &c);

        switch (id[0]){
            case 'a':
                for (int j = d; j <= m; j++){
                    v[j] += c;
                }
                break;
            case 'd':
                for (int j = d; j <= m; j++){
                    v[j] -= c;
                }
                break;

        }
    }


    uint64_t pm = 0;
    uint64_t pk = 0;

    for (int i=1; i <= m; i += 2){
        //std::cout << "for: " << i << "p: " << v[i]  << std::endl;
        pm = (v[i]>pm)?v[i]:pm;
    }

    for (int i=2; i <= m; i += 2){
        //std::cout << "for: " << i << "p: " << v[i]  << std::endl;
        pk = (v[i]>pk)?v[i]:pk;
    }

    printf("%ld %ld", pm, pk);

    return 0;
}