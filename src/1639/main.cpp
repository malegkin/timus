#include <iostream>

int main()
{   
    uint32_t m, n;
    std::cin >> m >> n;

    std::cout << ((m*n - 1)%2 ? "[:=[first]" : "[second]=:]") << std::endl; 
    return 0;
}
