#include <iostream>
#include <cmath>


//The sequence of positions of '1' in 1101001000... can be represented as (N*(N-1)/2+1). 

//Kn - Nth position of 1
//K1 = 1*0+1 = 1;
//K2 = 2*1/2+1 = 2;
//K3 = 3*2/2+1 = 4;
//Kn = n*(n-1)/2 + 1 ;

//Therefore, in order to solve the problem, it is necessary to solve equation
// n*(n-1)/2 + 1 = k;
// n^2 - n + 2 - 2*k = 0 
// n = 1/2 * (1 + sqrt(8*k - 7));
// So, k is a position of '1' if sqrt(8*k-7) is natural.



int main()
{
    uint32_t N;
    std::cin >> N;
 
    while(N--){
        uint64_t k;
        std::cin >> k;

        uint32_t n = round(0.5 * (1 + sqrt(8*k - 7)));

        if ( k == n*(n-1)/2 + 1 )
            std::cout << 1  << " ";
        else
            std::cout << 0  << " ";

    }
   
    return 0;
}