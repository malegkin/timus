
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define UNIVERSALL_SPELL_MAX_SIZE 50

char solve(const char* pIn){
    char counter[26];
    memset(counter, 0, 26);

    for (int i = 0; pIn[i] != '\0'; i++ ){
        counter[pIn[i] - 'a']++;
    }

    char max_c = 0;
    char max_i = 0;
    for (int i = 0; i < 26; i++){
        if (max_c < counter[i]){
            max_c = counter[i];
            max_i = i;
        }
    }

    return max_i + 'a';
}

int main(){

    #ifndef ONLINE_JUDGE
        assert(solve("qawaeara") == 'a');
        
        //freopen("test.cin", "rt", stdin);
    #endif
    
    char univesral_spell[UNIVERSALL_SPELL_MAX_SIZE + 1];
    memset(univesral_spell, '\0', UNIVERSALL_SPELL_MAX_SIZE +1);

    scanf("%s", univesral_spell);

    printf("%c", solve(univesral_spell));
    return 0;
}