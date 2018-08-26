//0.39s	    1'144 КБ
//150K
//real	0m0.137s
//user	0m0.127s
//sys	0m0.007s

#include <cstdio>
#include <string>

int main()
{
    uint32_t n;
    uint16_t a[150000];
    uint32_t hl[150000];
  
    #ifndef ONLINE_JUDGE
        freopen("t150k.cin", "rt", stdin);
    #endif

    scanf("%d", &n);
    for(uint32_t i=0; i<n; i++){
        scanf("%d %hd", &hl[i], &a[i]);
    }

    for(uint32_t v = 0; v <= 100; v++)   {
        for(uint32_t i = 0; i < n; i++)    {
            if (a[i] == 100 - v) 
                printf("%d %d\n", hl[i], a[i]);
        }
    }

  return 0;
}