#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <string>
#include <algorithm>


std::string read_file(std::string file_name){
    std::fstream fs(file_name);
    std::stringstream ss;
    ss << fs.rdbuf();
    fs.close();
    return ss.str();
}

std::string process(std::istream &in) {
    std::string out;


    return out;
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
