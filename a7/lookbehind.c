#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>


void lookBehind(const char* check, const char* s_sub, char* word) {
    
}

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
    
    return 0;
}


