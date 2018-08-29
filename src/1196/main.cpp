//Accepted	
//set: 1.326s	856
//map: 1.294s	3 848 КБ
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <set>
#include <map>
#include <vector>

int linetoi(std::istream& in ){
    std::string line;
    getline(in, line);
    return std::stoi(line);
}

std::string process_map(std::istream &in) {
    
    uint32_t N = linetoi(in);
    std::map<uint32_t, bool> professor_dates; 

    while(N--){
        professor_dates[linetoi(in)] = true;       
    }
    
    uint32_t M = linetoi(in);
    uint32_t out = 0;

    while(M--){
        if (professor_dates[linetoi(in)] )
            out++;
    }

    
    

   return std::to_string(out);
}


std::string process(std::istream &in) {
    
    uint32_t N = linetoi(in);
    std::set<uint32_t> professor_dates; 

    while(N--){
        professor_dates.insert(linetoi(in));       
    }
    
    uint32_t M = linetoi(in);
    uint32_t out = 0;

    while(M--){
        if (professor_dates.find(linetoi(in)) != end(professor_dates))
            out++;
    }

    
    /*
    std::set<uint32_t> student_dates; 
    while(M--){
        student_dates.insert(linetoi(in));
    }
    
    std::vector<uint32_t> out;
    std::set_intersection(begin(professor_dates), end(professor_dates), 
                    begin(student_dates), end(student_dates),
                    std::back_inserter(out));

    for(auto a: out){
        std::cout << a << std::endl;
    }

    return std::to_string(out.size());
    */

   return std::to_string(out);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.cin", "rt", stdin);
        assert(process_map(std::cin) == "2");
        return 0;
    #endif

    std::cout << process_map(std::cin) << std::endl;

    return 0;
}
