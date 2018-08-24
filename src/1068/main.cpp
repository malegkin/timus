#include <iostream>
#include <cstdlib>

int main()
{
    int32_t N;
    std::cin >> N;

    std::cout << (1 + N)*(abs(N - 1)+1)/2 << std::endl;

    return 0;
}

