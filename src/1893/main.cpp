#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

//SD = SEAT_DESIGNATION
const std::string SD_WINDOW   = "window";
const std::string SD_AISLE    = "aisle";
const std::string SD_NEITHER  = "neither";

std::string process(std::string&& in){
    std::string out;

    uint32_t seat_number = 0;
    std::transform(begin(in), end(in), begin(in), ::tolower);

    for(auto& a: in){
        switch(a){
            case '0'...'9':
                seat_number = 10*seat_number + a - '0';
            break;


            case 'a':
                out = SD_WINDOW;
            break;

            case 'b':
                out = (seat_number > 20) ? SD_NEITHER : SD_AISLE;
            break;

            case 'c':
                out = SD_AISLE;
            break;

            case 'd':
                out = (seat_number > 2) ? SD_AISLE : SD_WINDOW;
            break;

            case 'e':
                out = (seat_number > 20) ? SD_NEITHER : SD_AISLE;
            break;

            case 'f':
                out = (seat_number > 20) ? SD_NEITHER : SD_WINDOW;
            break;

            case 'g':
            case 'h':
                out = SD_AISLE;
            break;

            case 'j':
                out = SD_NEITHER;
            break;

            case 'k':
                out = SD_WINDOW;
            break;


            default:
                throw new std::invalid_argument(in);
            break;
        }
    }

    return out;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.cin", "rt", stdin);


        //premium
        assert(process("1A") == SD_WINDOW);
        //====
        assert(process("2B") == SD_AISLE);
        assert(process("1C") == SD_AISLE);
        //====
        assert(process("2D") == SD_WINDOW);

        //buisnes
        assert(process("3A") == SD_WINDOW);
        assert(process("6B") == SD_AISLE);
        //====
        assert(process("15C") == SD_AISLE);
        assert(process("18D") == SD_AISLE);
        //====
        assert(process("19E") == SD_AISLE);
        assert(process("20F") == SD_WINDOW);

        //premiuim
        assert(process("21A") == SD_WINDOW);
        assert(process("31B") == SD_NEITHER);
        assert(process("41C") == SD_AISLE);
        //====
        assert(process("51D") == SD_AISLE);
        assert(process("61E") == SD_NEITHER);
        assert(process("25F") == SD_NEITHER);
        assert(process("35G") == SD_AISLE);
        //====
        assert(process("45H") == SD_AISLE);
        assert(process("55J") == SD_NEITHER);
        assert(process("22K") == SD_WINDOW);
        
        //timus
        assert(process("3C") == "aisle");
        assert(process("64A") == "window");
        assert(process("21F") == "neither");
    #endif

    std::string in;
    getline(std::cin, in);

    std::cout << process(std::move(in)) << std::endl;

    return 0;
}
