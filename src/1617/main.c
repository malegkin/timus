
#include <stdio.h>
#include <string.h>


int main(){

    #ifndef ONLINE_JUDGE
        freopen("test.cin", "rt", stdin);
    #endif

    int wheels[101];
    memset(wheels, 0, sizeof(wheels));


    int n;
    scanf("%d", &n);

    while(n--){
        int wheel;
        scanf("%d", &wheel);
        if (wheel < 600)
            continue;

        wheels[wheel - 600]++;
    }


    int out = 0;

    for(int i = 0; i < 101; i++){
        out += wheels[i]/4;
    }

    printf("%u\n", out);

    return 0;
}