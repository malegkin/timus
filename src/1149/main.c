
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(){

    #ifndef ONLINE_JUDGE
        
        freopen("test.cin", "rt", stdin);
    #endif
    

    int n;
    scanf("%i", &n);
    for(int i=1; i<n; i++) 
        printf("(");

    for(int i=1; i <= n; i++)   {
        for(int j=1; j<=i; j++) {
            if(j > 1)
                printf((j&1)?"+":"-");
            printf("sin(%i",j);
        }

        for(int j=1; j<=i; j++){
            printf(")");
        }

        printf("+%i", n + 1 - i );

        if( i != n)
            printf(")");
    }


    return 0;
}