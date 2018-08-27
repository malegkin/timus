#include <iostream>
#include <string>
#include <algorithm>


//Basically, there are 2 "worst" cases:
//1). We take 40 right (equals 40*2=80 secs), then throw all the rest of the right 
    //ones (2*(b-40) secs), and them take the 40 left (40 secs). The time is 
    //80+2*(b-40)+40=120+2*(b-40).
//2). We take 39 left (78 secs), take 40 left ones (40 secs), throw all the other 
    //left ones away (2*(a-40)), and take the last right one (1 sec). The time 
    //is 78+40+2*(a-40)+1=119+2*(a-40).


int main()
{
    uint32_t a,b;
    std::cin >> a >> b;

    #ifndef ONLINE_JUDGE
        freopen("test.cin", "rt", stdin);
    #endif

    std::cout <<  std::max(120+2*(b-40), 119+2*(a-40)) << std::endl;

    return 0;
}
