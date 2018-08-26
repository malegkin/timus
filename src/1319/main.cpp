#include <iostream>
#include <string>

std::string process(const uint32_t N){
    std::string out;

    //table {1...N}x{1...N}
    uint32_t table[101][101]; 
    uint32_t n = 1;
    
    uint32_t x = N;
    uint32_t y = N;
    // first N-1 diagonals started from {N...2}xN
    for (; x > 1 ; x--  ){
        for(uint32_t i = x, j = y; i && i <= N  && j <= N && j; i++, j--){
            table[i][j] = n++;
        }
    }

    // last N diagonals started from 1x{N-1...1}
    for (; y ; y--  ){
        for(uint32_t i = x, j = y; i && i <= N  && j <= N && j; i++, j--){
            table[i][j] = n++;
        }
    }

    for (y = N; y > 0; y--){
        for (x = 1; x <= N; x++){
            out += std::to_string(table[x][y]) + " ";
        }
            out += "\n";
    }

    return out;
}

int main()
{
    uint32_t N;
    std::cin >> N;

    std::cout << process(N) << std::endl;

    return 0;
}