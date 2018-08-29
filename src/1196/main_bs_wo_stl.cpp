// binarySearch: 1.154s	280 KB

#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>


uint32_t  binarySearch(uint32_t  A[], uint32_t n, uint32_t x) {
    int low, high, mid;
    low = 0;
    high = n-1;

    while (low <= high) {
        mid = (low + high) / 2;
        if  (x == A[mid]) return(mid);
        else if (x < A[mid])  high = mid-1;
        else low = mid + 1;
    }
    return(-1);
}

int main() {
    uint32_t n, a[ 15001 ];
    uint32_t out = 0;

    scanf("%d", &n);
    for(uint32_t i =0; i < n; i++)
         scanf("%d", &a[i]);


    uint32_t m;
    scanf("%d", &m);
    while(m--) {
        uint32_t b;
        scanf("%d", &b);
        if (binarySearch(a, n, b ) != -1 )
            out++;
    }
    printf("%d\n", out);

    return 0;
}
