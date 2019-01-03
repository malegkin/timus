#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

const size_t SYMBOLS[] = { 0, 1, 6, 8, 9 };

size_t to_rotate_number(size_t in, size_t length) {
    size_t out = 0;

    while(length--){
        size_t n = in % 10;
        
        switch(in % 10){
            case 6:
                n = 9;
                break;
            case 9:
                n = 6;
                break;
        }
        out += n*pow(10, length);
        in = in / 10;
    }
    
    return out;
}


int main() 
{
    const size_t symbols_count = sizeof( SYMBOLS )/sizeof( SYMBOLS[0] );
    const size_t numbers_count = pow(symbols_count, 2);
    size_t numbers[numbers_count];
    assert( 5 == symbols_count);
    
    for (size_t i = 0; i < symbols_count; i++){
        for (size_t j = 0; j < symbols_count; j++){
            numbers[i*symbols_count + j] = SYMBOLS[i]*10 + SYMBOLS[j];
        }
    }   

    assert( 00 == numbers[00] );
    assert( 01 == numbers[01] );
    assert( 60 == numbers[10] );
    assert( 99 == numbers[24] );

    assert( 16 == to_rotate_number(91, 2) );
    
    size_t max_sequence_start  = 1;
    size_t max_sequence_length = 1;
    size_t sequence_start  = 1;
    size_t sequence_length = 1;    

    for(size_t i = 1; i < numbers_count; i++){
        //printf("%zu - %d\n", i, numbers[i]);
        if (numbers[i] - numbers[i-1] == 1){
            sequence_length++;
            continue;
        }
        
        if (sequence_length > max_sequence_length){
            //printf("\t new max sequence length: %zu\n", sequence_length);
            max_sequence_start  = sequence_start;
            max_sequence_length = sequence_length;
        }
            
        sequence_start  = i;
        sequence_length = 1;
    }
    if (sequence_length > max_sequence_length){
            max_sequence_start  = sequence_start;
            max_sequence_length = sequence_length;
    }
   
    assert( 4 == max_sequence_length);

    size_t n ;
    scanf("%zu", &n);   
    
    if (n > max_sequence_length) {
        printf("%s\n", "Glupenky Pierre");
        return 0;
    }
    
    while(n--){
        printf("%02zu\n", to_rotate_number(numbers[max_sequence_start + n], 2));  
    }

    return 0;
}
