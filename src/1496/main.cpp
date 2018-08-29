#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <map>
#include <vector>
#include <numeric>

std::string process(std::istream &in) { 

    std::map<std::string, uint32_t> commits_count;
    std::string line;
    uint32_t n ;
    in >> n;
    getline(in, line);

    while(n--){
        getline(in, line);
        commits_count[line]++;
    }

    //std::vector<std::pair<std::string, uint32_t>> out;
    //std::copy_if(begin(commits_count), end(commits_count), begin(out), [](auto& a){ return a.second > 1;});

    std::string out = std::accumulate(begin(commits_count), end(commits_count), std::string(), 
                            [](auto& a, auto& b){
                                if (b.second > 1)
                                    a +=  b.first + "\n";
                                return a;
                    });

    return out;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.cin", "rt", stdin);

        assert(process(std::cin) == "abikbaev\nx\n");
        
        return 0;
    #endif

    std::cout << process(std::cin) << std::endl;

    return 0;
}
