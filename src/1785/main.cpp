#include <iostream>
#include <string>

std::string translate(const int i)
{
    if ( i >= 1000 )
        return "legion";
    
    if ( i >= 500 )
        return "zounds";

    if ( i >= 250 )
        return "swarm";
    
    if ( i >= 100 )
        return "throng";

    if ( i >= 50 )
        return "horde";

    if ( i >= 20 )
        return "lots";
    
    if ( i >= 10 )
        return "pack";

    if ( i >= 5 )
        return "several";

    if ( i >= 1 )
        return "few";

    return "xz";
}

int main()
{    
    int i;
    std::cin >> i;

    std::cout << translate(i) << std::endl;

    return 0;
}