#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <string>
#include <algorithm>
#include <array>
#include <memory>
#include <cmath>

int main()
{
    uint16_t we; // west -> east
    uint16_t sn; // south -> north   
    uint16_t d; // diagonals
    std::cin >> we >> sn >> d;

    uint8_t grid[1001][1001] = {};
    uint8_t diagonally[1001][1001] = {};

    while (d--){
        uint16_t x,y;
        std::cin >>x >>y;
        diagonally[x][y] = 1;
    }

    for(size_t x = 1; x <= we; x++){
        for(size_t y = 1; y <= sn; y++){
            grid[x][y] = std::max( grid[x-1][y], grid[x][y-1] );
            if ( diagonally[x][y] )
                grid[x][y] = std::max( grid[x][y], static_cast<uint8_t>(grid[x-1][y-1] + 1));  
        }
    } 

    
    uint32_t out = 100*(we + sn - 2*grid[we][sn]) + round(grid[we][sn]*sqrt(20000.));

    std::cout << out << std::endl;    
        

    return 0;
}
