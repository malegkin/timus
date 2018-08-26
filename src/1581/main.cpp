#include <iostream>
#include <string>

int main()
{
    uint32_t N;
    std::cin >> N;


    uint32_t c = 0 , pc = 0, a = 0;
    while(N--){
        std::cin >> c;
        if (c == pc){
            a++;
        } else {
            if (a > 0)
                std::cout << a << " " << pc << " ";
            
            pc = c;
            a = 1;
        }
    }

    if (a > 0)
        std::cout << a << " " << pc << " ";

    return 0;
}