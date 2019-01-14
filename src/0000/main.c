
#include <stdio.h>
#include <string.h>
#include <assert.h>

char solve(const char* pIn){
    
    return pIn[0];
}

int main(){

    #ifndef ONLINE_JUDGE
        assert(solve("a") == 'a');
        
        freopen("./tests/1.in", "rt", stdin);
    #endif
    
    return 0;
}
