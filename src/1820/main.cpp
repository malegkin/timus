#include <iostream>
#include <cmath>

int main()
{
    uint32_t n, k;
    std::cin >> n >> k;


    //9 Women Can't Make a Baby in a Month
    if ( k > n )
        k = n;
    
    std::cout << ceil(2.*n/k) << std::endl;

   return 0;
}
