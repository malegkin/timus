#include <stdio.h>
#include <stdint.h>   

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

int main(){

    uint32_t n;
    scanf("%d", &n);

    //Jay Kadane algo
    int32_t gm = 0; //global_max
    int32_t lm = 0; //local_max
    
    while(n--) {
        int32_t i;
        scanf("%d", &i);
        
        lm += i;
        gm = MAX(lm, gm);
        lm = MAX(0, lm);
    }
           
    printf("%d", gm);
 
    return 0;
}
