#include <iostream>
#include <cmath>

int main()
{
    int32_t N;
    std::cin >> N;

    std::cout << (1 + N)*(1 + abs(N - 1))/2 << std::endl;

    return 0;
}

