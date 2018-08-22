//0.001s	548 KB

#include <iostream>
#include <cstring>

const size_t INPUT_BUFFER_SIZE  = 3*10*4000;

int main()
{    
    uint32_t N[3] = {0,0,0};
    uint32_t v[3][4000];

    uint8_t    in_buffer[INPUT_BUFFER_SIZE];
    memset(in_buffer, 0, INPUT_BUFFER_SIZE);
    size_t  in_buffer_size  = fread(in_buffer, 1, INPUT_BUFFER_SIZE, stdin);
    

    uint64_t in;
    uint32_t vi = 0, vj = 0;  
    bool is_number = false;
    for(size_t i = 0; vi < 3 ; i++) 
    {  
        switch(in_buffer[i]) {
            case '0' ... '9':
                in = (in * 10) + static_cast<uint32_t>(in_buffer[i] - '0');    
                is_number = true;
            break;
                
            default:
                if (!is_number)
                    break;

                if (N[vi] == 0){
                    N[vi] = in;
                    //std::cout << N[vi] << std::endl;
                } else {
                    v[vi][vj++] = in;
                    if (vj >= N[vi]){
                        vj = 0;
                        vi++;
                    }
                }

                in = 0;
                is_number = false;
                
            break;
        }
    }



    uint32_t out = 0;

    for (uint32_t i0 =0, i1=0, i2=0; i0 < N[0]; i0++){
        for ( ; v[0][i0] > v[1][i1] && i1 < N[1]; ){
            i1++;
        }
        for ( ; v[0][i0] > v[2][i2] && i2 < N[2]; ){
            i2++;
        }

        if (v[0][i0] == v[1][i1] && v[1][i1] == v[2][i2] ){
            //std::cout << v[0][i0] << std::endl;
            out++;
        }
    }

    std::cout << out << std::endl;
     
    return 0;
}