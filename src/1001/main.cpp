// Example program
#include <iostream>
#include <iomanip>

#include <vector>
#include <math.h>
#include <algorithm>

int main()
{    
    std::vector<double> in;
    uint64_t n;
    
    in.reserve(64*1000);
    
    for(int i = 0; i < 128*1000 && std::cin >> n; i++)
    {
        in.push_back(static_cast<double>(n));
    }
    
    std::cout.precision(4);
    std::cout << std::fixed;
    
    std::for_each(in.rbegin(), in.rend(), [](double& d){ printf("%.4f\n", sqrt(d)); });

    return 0;
}

