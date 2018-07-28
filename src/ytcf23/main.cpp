#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main()
{    
    int n;
    uint64_t r;
    std::cin >> n >> r;
    
    std::vector<uint64_t> v;
    v.reserve(n);

    for (int i =0; i < n; i++){
        uint64_t tmp;
        std::cin >> tmp;
        v.push_back(tmp); 
    }

    std::sort(std::begin(v), std::end(v));

    int p = 1;
    uint64_t p_max;

    for (int j = 0; j < n; j++){
        p_max = v[j-1] + r;
        if (v[j] - v[0] > r)
            break;
    }

    for (int i = 0; i < n; i++){
        if ( v[i] > p_max){
            p++;
            for (int j = i; j < n; j++){
                p_max = v[j-1]+r;
                if (v[j] - v[i] > r)
                    break;
            }
        }
    }

    std::cout << p;


    return 0;
}