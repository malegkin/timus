#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <vector>

std::string read_file(std::string file_name){
    std::fstream fs(file_name);
    std::stringstream ss;
    ss << fs.rdbuf();
    fs.close();
    return ss.str();
}

std::string process(std::istream &in) {
    size_t out = 0;
    size_t n;
    std::vector<size_t> wheels(101);

    in >> n;

    while(n--){
        size_t w;
        in >> w;
        wheels[w - 600]++;
    } 

    for(auto a: wheels)
        out += a / 4;

    return std::to_string(out);
}

std::string process(std::string in){
    std::stringstream ss(in);
    return process(ss);
}

int main()
{
    #ifndef ONLINE_JUDGE
        const std::string test_cout = read_file("test.cout");
        std::cout << "test_cout: [" << test_cout << "]" << std::endl;
        const std::string process_cout = process(read_file("test.cin"));
        std::cout << "process_cout: [" << process_cout << "]" << std::endl;
    
        assert(process_cout == test_cout);
        
        freopen("test.cin", "rt", stdin);
    #endif

    std::cout << process(std::cin) << std::endl;

    return 0;
}
