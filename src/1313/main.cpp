#include <iostream>
#include <string>

int main()
{
    uint32_t n;
    std::cin >> n;
    uint32_t x[101][101];
    for(int i = 1; i <= n; i++)
    {
        for(int j= 1; j <= n;j++) 
            std::cin >> x[i][j];
    }
    
    uint32_t i1 = 0;
    for(int i = 1; i <= n;i++)
    {
        for(int j = 1; j <= i;j++)
        {
            std::cout << x[i-i1][j] << " ";
            i1++;
        }
        i1 = 0;
    }
    int j1 =2,r=2;
    for(int i = 1;  i <= n-1;i++)
    {
        for(int j= n; j > i;j--)
        {
            std::cout << x[j][j1] << " ";
            j1++;
        }
        r++;
        j1 =r;
    }
    return 0;
}
