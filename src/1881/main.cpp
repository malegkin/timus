#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <cmath>

std::string process(std::istream &in) {
    
    uint32_t lines_on_page, symbols_on_line, n;
    in >> lines_on_page >> symbols_on_line >> n;

    std::string line;
    getline(in, line);
    uint32_t lines_count = 1, symbols_count = 0;
    while(n--){
        getline(in, line);
        symbols_count += line.size();
        if (symbols_count > symbols_on_line){
            lines_count++;
            symbols_count = line.size();
        }
        symbols_count++;
    }
    
    uint32_t pages = lines_count / lines_on_page + 
            (((lines_count % lines_on_page) > 0) ? 1 : 0 );

    
    return std::to_string(pages);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.cin", "rt", stdin);

        std::stringstream ss(
"3 5 6\n\
To\n\
be\n\
or\n\
not\n\
to\n\
be\n");
        assert(process(ss) == "2");

        std::stringstream ss2(
"2 11 12\n\
aaaa\n\
bb\n\
ccc\n\
ddddddddddd\n\
eeeeeeee\n\
ff\n\
jjjjj\n\
hhhh\n\
iiiii\n\
jjjjjjjjjj\n\
kk\n\
lll\n");
        assert(process(ss2) == "4");

        assert(process(std::cin) == "2");
        return 0;

    #endif

    std::cout << process(std::cin) << std::endl;

    return 0;
}
