#include <stdio.h>
#include <stdint.h>
#include <float.h>

int main() {
    double p, q;
    scanf("%lf %lf", &p, &q);

    size_t out = 1;
    do {
        out++;
    } while ( (size_t)(p*out + 1e-2) / 100 ==  (size_t)(q*out - 1e-2) / 100 );
    
    printf ("%d\n", out);
        
    return 0;
}
