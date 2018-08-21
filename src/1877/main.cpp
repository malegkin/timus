#include <iostream>
#include <string>

std::string is_opened(const uint32_t first_lock, const uint32_t second_lock)
{
    if (first_lock % 2 == 0 || second_lock % 2 == 1)
        return "yes";

    return "no";
}

int main()
{    
    uint32_t first_lock, second_lock;
    std::cin >> first_lock >> second_lock;

    std::cout << is_opened(first_lock, second_lock) << std::endl;

    return 0;
}