#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main() {

    double p, q, eps;
    scanf("%lf %lf", &p, &q);

    uint64_t up = round(p*100);
    uint64_t uq = round(q*100);
  
    size_t out = 1;
    do {
        out++;
    } while ( (up * out + 1) / 10000  ==  (uq * out - 1) / 10000 );
    
    printf ("%d\n", out);
        
    return 0;
}
