#include <iostream>

int main()
{
    uint32_t a[3], b[3];
    for (int i = 0; i < 3; i++){
        std::cin >> a[i] >> b[i];
    }

    printf("%d\t%d\n", (a[0] - a[2]), (b[0] - b[1]));

   return 0;
}
