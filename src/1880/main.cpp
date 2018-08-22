#include <iostream>


int main()
{    
    uint32_t N[3] = {0,0,0};
    uint32_t v[3][4000];

    
    for (uint32_t i = 0; i < 3; i++){
       std::cin >> N[i];
       for (uint32_t j =0; j < N[i]; j++){
            scanf("%d", &v[i][j]);
            //std::cin >> v[i][j];    
       }
    }
    

 
    uint32_t out = 0;

    for (uint32_t i0 =0, i1=0, i2=0; i0 < N[0]; i0++){
        for ( ; v[0][i0] > v[1][i1] && i1 < N[1]; ){
            i1++;
        }
        for ( ; v[0][i0] > v[2][i2] && i2 < N[2]; ){
            i2++;
        }

        if (v[0][i0] == v[1][i1] && v[1][i1] == v[2][i2] ){
            //std::cout << v[0][i0] << std::endl;
            out++;
        }
    }

    std::cout << out << std::endl;
     
    return 0;
}