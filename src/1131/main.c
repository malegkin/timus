#include <stdio.h>


int main ()
{
    int n, k;
    scanf ("%d%d", &n, &k);

    int p = 0;
    while( (1 << p) < k && ( 1 << p) < n )
        p++;

    if ((1 << p) < n) 
            p += (k + n - (1 << p) - 1) / k ;
  
    printf ("%d\n", p);
    return 0;
}
