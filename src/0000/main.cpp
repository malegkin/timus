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

std::string solve(std::istream &in) {
    std::string out;


    return out;
}

std::string solve(std::string in){
    std::stringstream ss(in);
    return solve(ss);
}

int main()
{
    #ifndef ONLINE_JUDGE
        auto test_cout = read_file("test.cout");
        test_cout.pop_back();
        std::cout << "\ttest_cout: [" << test_cout << "]" << std::endl;

        auto solve_cout = solve( read_file("test.cin") );
        std::cout << "\tsolve_cout: [" << solve_cout << "]" << std::endl;
    
        assert(solve_cout == test_cout);       
 
        freopen("test.cin", "rt", stdin);
    #endif

    std::cout << solve( std::cin ) << std::endl;

    return 0;
}
