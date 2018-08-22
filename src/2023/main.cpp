#include <iostream>
#include <string>
#include <cmath>


int32_t get_post_case_offset(const std::string& receiver)
{
    uint32_t out = 0;
    switch (receiver[0]){
        case 'A':
        case 'P':
        case 'O':
        case 'R':
            out = 0;
            break;
        
        case 'B':
        case 'M':
        case 'S':
            out = 1;
            break;

        default:
            out = 2;
    }

    return out;
}

std::string get_receiver(){
    std::string out;
    std::cin >> out;
    return std::move(out);
}

int main()
{
    uint32_t n;
    std::cin >> n;

    uint32_t steps = 0;
    int32_t last_offset = 0;
    
    for (;n;n--){
        int32_t offset = get_post_case_offset(get_receiver());
        steps += abs(last_offset - offset);
        last_offset = offset;
    }

    std::cout << steps << std::endl;
    
   return 0;
}
