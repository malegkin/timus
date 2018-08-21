#include <iostream>
#include <string>

int main()
{
    uint32_t k, n;
    int32_t cars_in_jam = 0;

    std::cin >> k >> n;

    for (uint32_t i = 0; i < n; i++){
        int32_t ai;
        std::cin >> ai;

        cars_in_jam += (ai - k);

        if (cars_in_jam < 0 )
            cars_in_jam = 0;        
    }

    std::cout << cars_in_jam << std::endl; 

   return 0;
}