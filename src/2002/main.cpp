#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <map>
#include <fstream>

std::string read_file(std::string file_name){
    std::ifstream fs(file_name);
    std::stringstream ss;
    ss << fs.rdbuf();
    fs.close();
    return ss.str();
}

std::string process(std::istream &in) {
    std::ostringstream oss;
    std::map<std::string, std::pair<std::string, bool>> users;
    uint16_t n;
    
    in >> n;

    while(n--){
        std::string command, user, password;
        in >> command >> user;

        bool is_registered_user = ( users.find(user) != std::end(users) );
              
        switch(command.size()){
            //register == 8
            case 8: 
                in >> password;
                if (is_registered_user){
                    oss << "fail: user already exists\n";
                } else {
                    users[user] = std::make_pair(password, false);
                    oss << "success: new user added\n";
                }
            break;
            
            //login == 5
            case 5:
                in >> password;
                if (is_registered_user) {
                    if (users[user].first == password){
                        oss << ((users[user].second)?"fail: already logged in\n":"success: user logged in\n");
                        users[user].second = true;
                    } else {
                        oss << "fail: incorrect password\n";
                    }
                } else {
                    oss << "fail: no such user\n";
                }
            break;

            //logout == 6
            case 6:
                if (is_registered_user){
                    oss << ((users[user].second)?"success: user logged out\n":"fail: already logged out\n");
                    users[user].second = false;
                } else {
                    oss << "fail: no such user\n";
                }
        };
    
    }
    
    

    return oss.str();
}

std::string process(std::string in){
    std::stringstream ss(in);
    return process(ss);
}

int main()
{
    #ifndef ONLINE_JUDGE
        std::string process_cout = process(read_file("test.cin"));
        std::cout << "process_cout: [" << process_cout << "]" << std::endl;
        std::string test_cout = read_file("test.cout");
        std::cout << "test_cout: [" << test_cout << "]" << std::endl;
        assert(process_cout == test_cout);

    
 
        freopen("test.cin", "rt", stdin);
    #endif

    std::cout << process(std::cin) << std::endl;

    return 0;
}
