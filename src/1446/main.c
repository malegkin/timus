#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define ALLOC_PAGE_SIZE 4096

static const char* HOUSE_NAME[] = { "Ravenclaw", "Gryffindor", "Hufflepuff", "Slytherin" };

inline const int get_id( const char* house ){
    switch( tolower(house[0]) ){
        case 's':
            return 3;

        case 'h':
            return 2;

        case 'g':
            return 1;

        case 'r':
            return 0;
    }    

    return -1;
}

struct house_data {
    size_t size;
    size_t max_size;

    char* out;
};

int main(){

    uint16_t n;
    scanf("%hd\n", &n);
    
    struct house_data hogwarts[3]; //never save Slytherin's students ))

    for (size_t i = 0; i < 3; i++){
        hogwarts[i].size = 0;
        hogwarts[i].max_size = ALLOC_PAGE_SIZE;
        hogwarts[i].out = (char*)malloc( ALLOC_PAGE_SIZE );
    }


    printf("%s:\n", HOUSE_NAME[3] );
    while( n-- ) {
        //char* house = NULL;
        //char* name = NULL;
        //size_t len_h = 0, len_n = 0;         
        //getline( &name, &len_h, stdin);
        //getline( &house, &len_n, stdin);
        
        char house[20];
        char name[207];
        gets( name ); 
        gets( house );
        int id = get_id( house );
        size_t name_size = strlen( name );

        if (id == 3) {
            printf("%s\n", name);
            continue;
        }        

        if (hogwarts[ id ].size + name_size + 2 > hogwarts[ id ].max_size) {
            hogwarts[ id ].out = (char*)realloc( hogwarts[ id ].out, hogwarts[ id ].max_size + ALLOC_PAGE_SIZE);
            hogwarts[ id ].max_size += ALLOC_PAGE_SIZE; 
        }
        memcpy( hogwarts[ id ].out + hogwarts[ id ].size, name, name_size );
        hogwarts[ id ].size += name_size + 1 ;
        hogwarts[ id ].out[ hogwarts[ id ].size - 1 ] = '\n';
        hogwarts[ id ].out[ hogwarts[ id ].size     ] = 0;
    }

    printf("\n");
    size_t id = 3;
    while (id--){
        printf("%s:\n%s\n", HOUSE_NAME[ id ], hogwarts[ id ].out);
    }
 
    return 0;
}
