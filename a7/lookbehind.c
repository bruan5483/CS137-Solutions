#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool cBehind(const char* s_sub, char* word, int pos){
    if(pos + strlen(s_sub) > strlen(word)) return false;
    for(int i = 0; i < strlen(s_sub); i++){
        if(s_sub[i] != word[pos+i]) return false;
    }
    return true;
} 

void lookBehind(const char* check, const char* s_sub, char* word) {
    for(int i = 0; i < strlen(word); i++){
        bool lead = true;
        for(int k=0;k<strlen(check);k++){
            if(i+strlen(check)>=strlen(word) || check[k]!=word[i+k]) {
                lead=false;
                break;
            }
        }
        while(lead && cBehind(s_sub,word,i+strlen(check))){
            for(int j = i+strlen(check); j<strlen(word)-strlen(s_sub); j++){
                word[j]=word[j+strlen(s_sub)];
            }
            word[strlen(word)-strlen(s_sub)] = '\0';
        }
    }
    return;
}
/*
int main(void){
    
    char word[] = "foo bar loop hoop" ;
    lookBehind("l", "oo", word);
    assert(0==strcmp("foo bar lp hoop", word));
	lookBehind("o", "o", word);
    assert(0==strcmp("fo bar lp hop", word));
    
    char word3[] = "CS137137" ;
    lookBehind("CS", "137", word3);
    assert(0==strcmp("CS", word3));
    char word3b[] = "CS137 137" ;
    lookBehind("CS", "137", word3b);
    assert(0==strcmp("CS 137", word3b));
    
    char word4[] = "111111" ;
    lookBehind("1", "1", word4);
    assert(0==strcmp("1", word4));
    

    char word5[] = "wow" ;
    lookBehind("", "w", word5);
    assert(0==strcmp("o", word5));
    


   char word6[] = "113731377" ;
    lookBehind("", "137", word6);
    assert(0==strcmp("137", word6));


    return 0;
}
*/