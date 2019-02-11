// Classic game theory problem, can be solved with SG
// https://en.wikipedia.org/wiki/Sprague%E2%80%93Grundy_theorem

#include <iostream>
#include <cassert>
#include <string>

int main()
{
    size_t n;
    std::cin >> n;
    //cos both play optimally 
    // (2*N + 1) => 1 + 1 + (2*(N-1)+1)
    // each heaps can be optimally divides to mininal sub-heaps in N steps
    size_t steps = 0;
    while (n--) {
        size_t h;
        std::cin >> h;
        steps += h / 2;    
    }

    // Daenerys has dragons so she moves First &&
    // The player who cannot make a move loses => 
    // if optimal steps count is odd number => Sannis win

    if (steps % 2)
        std::cout << "Daenerys" << std::endl;
    else
        std::cout << "Stannis" << std::endl;
    
    return 0;
}
