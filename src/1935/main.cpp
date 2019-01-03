#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
 
int main()
{
    std::vector<uint16_t> in;
    uint16_t n;
    std::cin >> n;
    while(n--){
        uint16_t ai;
        std::cin >> ai;
        in.push_back(ai);
    }
    
    uint16_t sum = 0;
    uint16_t max = 0;
    std::for_each(std::begin(in), std::end(in), [&](auto a) {
        sum += a;
        max = (a > max)?a:max;
    });
    
    std::cout << (sum + max);
    return 0;
}
