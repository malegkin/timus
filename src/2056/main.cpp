#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <sstream>

static const std::string EVAL_NAME     = "Named";
static const std::string EVAL_HIGH     = "High";
static const std::string EVAL_COMMON   = "Common";
static const std::string EVAL_NONE     = "None";

int linetoi(std::istream& in ){
    std::string line;
    getline(in, line);
    return std::stoi(line);
}

std::string linetos(std::istream& in ){
    std::string line;
    getline(in, line);
    return line;
}

std::string process(std::istream &in) {
    
    uint32_t n          = linetoi(in);
    uint32_t sum        = 0;
    bool     is_none    = false;

    for(int i = 0; i < n; i++) {
        int eval = linetoi(in);
        if (eval == 3)  
            is_none = true;
        sum += eval;
    }

    if ( is_none )
        return EVAL_NONE;

    if (sum == 5*n)
        return EVAL_NAME;

    if ( 10*sum/n%10 >= 5  )
        return EVAL_HIGH;

    return EVAL_COMMON;
}

std::string process(std::string in){
    std::stringstream ss(in);
    return process(ss);
}

int main()
{
    #ifndef ONLINE_JUDGE
        assert(process("1\n5\n")        == EVAL_NAME);
        assert(process("2\n5\n4\n")     == EVAL_HIGH);
        assert(process("3\n5\n4\n4\n")  == EVAL_COMMON);
        assert(process("3\n5\n3\n5\n")  == EVAL_NONE);
        
        freopen("test.cin", "rt", stdin);
    #endif

    std::cout << process(std::cin) << std::endl;

    return 0;
}
