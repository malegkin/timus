#include <iostream>
#include <string>

int main()
{
    uint32_t n;
    std::cin >> n;

    uint32_t cost = n + 2; // Lily and Marshal eat to

    for ( ; n ; n--){
        std::string guest;
        std::cin >> guest;
        if ( guest[guest.length() - 4] == '+' )
            cost++;
    }

    if (cost == 13)
        cost++;

    std::cout << cost * 100 << std::endl;

    return 0;
}
