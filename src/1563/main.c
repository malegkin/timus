#include <stdio.h>
#include <string.h>
#include <assert.h>

#define INPUT_MAX_LENGTH (30+2)     //only for windows need '\r\n'

int main(){

    size_t n;
    size_t out = 0;
    scanf("%d", &n);

    char in[n][ INPUT_MAX_LENGTH ];
    memset(in, 0, n*INPUT_MAX_LENGTH);

    fgets(in[0], INPUT_MAX_LENGTH, stdin);        
    for (size_t i = 0; i < n; i++) {
        fgets(in[i], INPUT_MAX_LENGTH, stdin);
        for (size_t j = 0; j < i; j++){
            if ( !strcmp(in[i], in[j]) ){
                out++;
                break;
            }
        }    
    }       
 
    printf("%d", out);
    return 0;
}
