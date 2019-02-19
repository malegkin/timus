#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdint.h>

#define MAX(x,y) ((x)>(y)?(x):(y))


int32_t kadane_1d( size_t size, int32_t in[size] ){
    int32_t gm = INT_MIN; // global_max
    int32_t lm = 0;

    for (size_t i = 0; i < size; i++){
        lm += in[i];
        gm = MAX(lm, gm);
        lm = MAX(0, lm);
    }

    return gm ;
}

int32_t kadane_2d( size_t width, size_t height, int32_t in[width][height] ){
    int32_t gm = INT_MIN;
    int32_t tmp[height];
 
    for (size_t i_left = 0; i_left < width; ++i_left){
        memset( tmp, 0, 4*height );
        for (size_t i_right = i_left; i_right < width; ++i_right){
            for (size_t i = 0; i < height; i++)
                tmp[i] += in[i_right][i];
            
            gm = MAX(gm, kadane_1d(height, tmp));
        }
    }

    return gm;
}


int main() {
    
    size_t n;
    scanf("%d", &n);

    int32_t in[n][n];    
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            scanf("%d", &in[i][j]);
        }
    }

    printf ("%d\n", kadane_2d(n, n, in));
        
    return 0;
}
