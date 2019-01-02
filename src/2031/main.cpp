#include <iostream>
#include <string>
#include <vector>
#include <cmath>
 
std::string to_rotate_number(uint16_t in, size_t length){
    std::string out;
    
    while(length--){
        auto a = in%10;
        switch (a){
            case 9:
                a = 6;
                break;
            case 6:
                a = 9;
                break;
        }
        out += std::to_string(a);
        in = in/10;
    }
    
    return out;
}

std::vector<uint16_t> get_longest_sequence(){
    std::vector<uint16_t> out;
    uint16_t symbols[] = {0,1,6,8,9};
    
    std::vector<uint16_t> tmp;
    for (auto s1: symbols) {
        for (auto s2: symbols) {
            uint16_t t = s1*10 + s2;
            
            if ( tmp.empty() ) {
                tmp.push_back(t);
                continue;
            }
            
            if (t - *tmp.rbegin() > 1)  {
                if ( tmp.size() > out.size()) {
                    //std::cout << "new out with size: " << std::size(tmp) << std::endl;
                    out = tmp;
                }
                tmp = {};
            }
            
            //std::cout << "push: " << t << std::endl;
            tmp.push_back(t);
        }
    }
    
    return out;
}


int main()
{
    auto sequence = get_longest_sequence();
    uint16_t in;
    std::cin >> in;
    if (in > sequence.size()){
        std::cout << "Glupenky Pierre" << std::endl;
    } else {
        while (in--){
            std::cout << to_rotate_number(sequence[in],2) << std::endl;
        }
    }


    return 0;
}
