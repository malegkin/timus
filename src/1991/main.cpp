#include <iostream>
#include <string>
#include <sstream>

int main()
{
    uint32_t n, k;
    std::cin >> n >> k;

    std::string in;
    getline(std::cin, in);
    getline(std::cin, in);
    std::stringstream ssin(in);

    uint64_t droids = 0, booms = 0;
    for(uint32_t i =0; i < n; i++){

        int32_t b;
        ssin >> b;
        
        int32_t d = b - k;
        if(d > 0){
            booms += d;
        } else {
            droids += abs(d);
        }
    }

    std::cout << booms << " " << droids << std::endl;

    return 0;
}