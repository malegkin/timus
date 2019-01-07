#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <string>
#include <algorithm>
#include <tuple>

std::string read_file(std::string file_name){
    std::fstream fs(file_name);
    std::stringstream ss;
    ss << fs.rdbuf();
    fs.close();
    auto out =  ss.str();
    out.pop_back();
    return std::move(out);
}



std::string process(std::istream &in) {
    std::string cm; //Cipher message

    in >> cm;

    if (cm.size() < 2)
        return cm;

    size_t out_size = cm.size();


    auto it = std::begin(cm);
    auto it_prev = it;
    for (; (it+1) != std::end(cm); it++){
        if (*it == '#')
            continue;

        auto it_next = it+1;

        if (*it != *it_next){
            it_prev = it ;
            continue;
        }

        *it = '#';
        *(it_next++) = '#';
        out_size -= 2;


        while ( it_next != std::end(cm) && it_prev != std::end(cm) ){
            while(it_prev != std::end(cm) && *it_prev == '#')
                it_prev --;

            if ( *it_next != *it_prev ) {
                it = it_next - 1;
                break;
            }

            *(it_next++) = '#';
            *(it_prev--) = '#';
            out_size -= 2;
        }

    }


    std::string out;

    std::copy_if(std::begin(cm), std::end(cm), std::back_inserter(out), [](auto a){
        return (a != '#');
    });


    return std::move(out);
}

std::string process(std::string in){
    std::stringstream ss(in);
    return process(ss);
}

int main()
{
    #ifndef ONLINE_JUDGE
        assert(process("a") == "a");
        assert(process("") == "");
        assert(process("aa") == "");
        assert(process("hgfedcbaabcdefgh") == "");
        assert(process(std::string("qhgfedcbaabcdefgh") + "hgfedcbaabcdefghq") == "");

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
