//(c): saba_tavdgiridze && hoan

#include <cstdio>

int main (){
    char ch, res = 0;
    while ((ch = getchar()) != '\n' ) 
        res= (10*res + ch-'0') % 7;
    printf("%d\n", res);
    return 0;
}