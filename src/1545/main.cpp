#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cassert>
#include <numeric>
#include <sstream>
#include <algorithm>

std::string process(std::istream &in){
    std::string line;
    getline(in, line);
    int32_t N = std::stoi(line);

    std::map<char, std::vector<std::string>> hieroglyphs; 

    while(N--){
        getline(in, line);
        hieroglyphs[line[0]].push_back(std::move(line));
    }

    getline(in, line);
    if (hieroglyphs.find(line[0]) == end(hieroglyphs))
        return "";

    auto results = std::move(hieroglyphs[line[0]]);

    std::sort(begin(results), end(results));
    std::string out = std::accumulate(++begin(results), end(results), std::string(results[0]),
            [](auto a, auto b){ return a + "\n" + b;});

    return out;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.cin", "rt", stdin);

        std::stringstream ss1("1\npp\nk");
        assert(process(ss1) == "");
    #endif

    std::cout << process(std::cin) << std::endl;

    return 0;
}
