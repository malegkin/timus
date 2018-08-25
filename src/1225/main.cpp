#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector<std::string> get_flags(uint32_t N, std::vector<std::string> flags );
std::vector<std::string> get_flags(uint32_t N){
    std::vector<std::string> out;

    //out.push("b"); //A blue stripe must always be placed between a white 
                        //and a red or between a red and a white one.
    out.push_back("w");
    out.push_back("r");

    if (!--N)
        return out;

    return get_flags(N, out);
}

std::vector<std::string> get_flags(uint32_t N, std::vector<std::string> flags ){
    std::vector<std::string> out;


    for(std::string flag: flags){
        switch ( flag.back() )
        {
            case 'b': {  //blue
                char c = flag[flag.length() - 2 ];
                out.push_back(flag + (c == 'r'?'w':'r'));
                break;
            }
            
            case 'w': {  //white
                if (N > 1)
                    out.push_back(flag + 'b');
                out.push_back(flag + 'r');
                break;
            }

            case 'r':  { //red
                if (N > 1)
                    out.push_back(flag + 'b');
                out.push_back(flag + 'w');
                break;
            }
        }
    }

    if (!--N)
        return out;

    return get_flags(N, out);
}

std::map<std::string, uint32_t> get_flags_counters(uint32_t N, std::map<std::string, uint32_t>&& flags_counter );
std::map<std::string, uint32_t> get_flags_counters(uint32_t N){
    std::map<std::string, uint32_t> out;

    //out["r"] = 1;
    //out["w"] = 1;
    out["rb"] = 0;
    out["rw"] = 0;
    out["bw"] = 1;
    out["br"] = 1;
    out["wb"] = 0;
    out["wr"] = 0;

    if (!--N)
        return out;

    return get_flags_counters(N, std::move(out));
}

std::map<std::string, uint32_t> get_flags_counters(uint32_t N, std::map<std::string, uint32_t>&& flags_counter ){
    std::map<std::string, uint32_t> out;

    if (N > 1)  {
        out["rb"] = flags_counter["wr"] + flags_counter["br"];
        out["wb"] = flags_counter["rw"] + flags_counter["bw"];
    }

    out["bw"] = flags_counter["rb"];
    out["br"] = flags_counter["wb"];

    out["rw"] = flags_counter["wr"] + flags_counter["br"];
    out["wr"] = flags_counter["rw"] + flags_counter["bw"];

    if (!--N)
        return std::move(out);

    return get_flags_counters(N, std::move(out));
}




int main()
{
    uint32_t N;
    std::cin >> N;

    //auto flags = get_flags(N);

    uint32_t out = 0;

    for (const auto& kv:  get_flags_counters(N)){
        out += kv.second;
    }

    std::cout << out << std::endl;

    return 0;
}
