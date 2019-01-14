#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);
    
    unsigned long long out = 0;
    do {
        out += (1+n)*n + (1+n)*n/2;
    } while(n--);

    printf("%llu\n", out);
}
