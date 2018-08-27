#include <iostream>
#include <string>


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.cin", "rt", stdin);
    #endif

    uint32_t A, B;
    std::cin >> A >> B;

    std::cout << (B - A + (A%2) + (B%2)) / 2 << std::endl;

    return 0;
}
