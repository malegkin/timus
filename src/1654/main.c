// AC: time: 0.001s memory: 604KB

#include <stdio.h>
#include <string.h>
#include <assert.h>

const size_t INP_BUFFER_CAPACITY = 200*1000 + 1;
const size_t OUT_BUFFER_CAPACITY = 200*1000 + 1;

const char*  solve(const char* pIn, char* pOut)
{
    size_t j = 0;
    for (size_t i = 0; pIn[i] != '\0'; i++){
        if (j == 0 || pIn[i] != pOut[j-1]){
            pOut[j++] = pIn[i];
        } else {
            j--;
        }
    }

    pOut[j] = '\0';

    return pOut;
}

int main()
{
    char    out_buffer[OUT_BUFFER_CAPACITY];
    char    inp_buffer[INP_BUFFER_CAPACITY];

    #ifndef ONLINE_JUDGE
        assert( !strcmp(solve("a", out_buffer), "a") );
        assert( !strcmp(solve("", out_buffer), "") );
        assert( !strcmp(solve("aa", out_buffer), "") );
        assert( !strcmp(solve("hgfedcbaabcdefgh", out_buffer), "") );
        assert( !strcmp(solve("qhgfedcbaabcdefghhgfedcbaabcdefghq", out_buffer), "") );
        assert( !strcmp(solve("qhgfedcbaabcdefghrhgfedcbaabcdefghq", out_buffer), "qrq") );

        freopen("test.cin", "rt", stdin);
    #endif

    puts( solve(gets(inp_buffer), out_buffer) );

    return 0;
}