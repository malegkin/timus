#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main(){
    uint32_t n;
    scanf("%u", &n);

    uint32_t p = sqrt(n) + 5;
    uint32_t s; 
    do {
        p--; 
        s = p*(p+1)/2;
    } while ( n < s || (n-s)%p );

    printf("%u %u", (n - s)/p + 1,  p);
        
    return 0;
}
