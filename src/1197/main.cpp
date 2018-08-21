#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>


class ChessboardSquare
{
    //internal representation of coordinates on the chessboard square:
    // x - {0...7}
    // y - {0...7}
    int8_t _x;
    int8_t _y;

    public:
        ChessboardSquare ( const int8_t x, const int8_t y )
            :_x(x)
            ,_y(y)
            {}

        ChessboardSquare( std::string xy )
        {
            switch(xy[0]){
                case 'A'...'H':
                    _x = static_cast<uint8_t>(xy[0]) - 'A';
                    break;
                case 'a'...'h':
                    _x = static_cast<uint8_t>(xy[0]) - 'a';
                    break;
                default:
                    throw std::invalid_argument(xy);
            }

            switch(xy[1]){
                case '1'...'8':
                    _y = static_cast<uint8_t>(xy[1]) - '1';
                    break;
                default:
                    throw std::invalid_argument(xy);
            }


        }

        bool is_valid(){
            if (_x  < 0 ||  _x > 7 || _y < 0 || _y > 7)
                return false;

            return true;
        }
    
        std::string to_string(){
            std::string out;
            out += static_cast<char>(_x+'A');
            out += static_cast<char>(_y+'1');
            
            return out;
        }

        ChessboardSquare get_offset_square(int8_t x, int8_t y){
            return std::move(ChessboardSquare(_x + x, _y + y));
        }    
};

class ChessKnight {

    ChessboardSquare _xy;

    public:
        ChessKnight(const std::string& xy)
            :_xy(xy)
            {}

        std::vector<ChessboardSquare> get_under_attack_squares(){
            std::vector<ChessboardSquare> out;

            //TODO: add automatic generation of the set of offsets for knight

            int8_t chess_knight_square_offsets[8][2] = { {2,1}, {2,-1}, {-2,1}, {-2,-1},
                 {1,2}, {1,-2}, {-1,2}, {-1,-2}};

            for (int i = 0; i < 8; i++){
                ChessboardSquare new_square = _xy.get_offset_square(chess_knight_square_offsets[i][0], chess_knight_square_offsets[i][1]);
                if (new_square.is_valid()){
                    //std::cout << new_square.to_string() << std::endl;
                    out.push_back(new_square);
                }
            }

            return out;
        }

};


int main()
{
    uint32_t N;
    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::string line;
        std::cin >> line;
        try{
            std::cout << ChessKnight(line).get_under_attack_squares().size() << std::endl;
        } catch(std::exception ex){
            std::cout << ex.what();
            return -1;
        }
    }
    
   return 0;
}
