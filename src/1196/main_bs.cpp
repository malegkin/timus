// binarySearch: 1.126s	280 KB

#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <array>


int main() {
    uint32_t n;
    std::array<uint32_t, 15000> a;
    uint32_t out = 0;

    scanf("%d", &n);
    for(uint32_t i =0; i < n; i++)
         scanf("%d", &a[i]);


    uint32_t m;
    scanf("%d", &m);
    while(m--) {
        uint32_t b;
        scanf("%d", &b);
        if (std::binary_search(begin(a), begin(a)+n, b) )
            out++;
    }
    printf("%d\n", out);

    return 0;
}