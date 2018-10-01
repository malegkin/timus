
#include <stdio.h>
#include <string.h>
#include <assert.h>

char* solve(const int N, char* str){

    memset (str, 0, sizeof(str));
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

    return str;
}


int main(){

    #ifndef ONLINE_JUDGE
        char out[200*1000];
        assert( strcmp(solve(3, out), "((sin(1)+3)sin(1–sin(2))+2)sin(1–sin(2+sin(3)))+1") );
        assert( solve(200, out)  );        
        freopen("test.cin", "rt", stdin);
    #endif
    

    int n;
    scanf("%i", &n);


    return 0;
}