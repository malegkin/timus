#include <iostream>
#include <string>

std::string process(const std::string in){
    uint32_t out = 0;

    for(const char c: in){
        switch(c){
            case 'a':
            case 'd':
            case 'g':
            case 'j':
            case 'm':
            case 'p':
            case 's':
            case 'v':
            case 'y':
            case '.':
            case '_':
            case ' ':
                out += 1;
            break;

            case 'b':
            case 'e':
            case 'h':
            case 'k':
            case 'n':
            case 'q':
            case 't':
            case 'w':
            case 'z':
            case ',':
                out += 2;
                break;
            
            default:
                out += 3;

        }
    }

    return std::to_string(out);
}

int main()
{
    std::string in;
    getline(std::cin, in);

    std::cout << process(in) << std::endl;

    return 0;
}
