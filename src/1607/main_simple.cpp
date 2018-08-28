#include <cstdio>

int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    while(a <= c) {
        a += b;
        a = (a > c ? c : a);
        c -= d;  
    }

    printf("%d\n", a);

    return 0;
}