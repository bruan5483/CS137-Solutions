//Implement the following function:
//returns the length of the longest palindrome in st between index start and index end (inclusive for both)

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//checks if a string is a palindrome
bool ispalindrome(char *st){
    int len = strlen(st);
    int i = 0;
    char *ret = malloc((len+1)*sizeof(char));
    while(st[i]){
        ret[len-1-i] = st[i];
        i++;
    }
    ret[len] = '\0';
    int res = strcmp(st, ret);
    free(ret);
    if(res == 0) return true;
    return false;
}

//helper function for longestpalindrome to keep track of longest length substring to check
int help(char *st, int start, int end, int totlen, int currlen){
    if (start==end) return 1;
    int curr = 0;
    while(curr + currlen <= totlen){
        char* temp = malloc((currlen+1)*sizeof(char));
        for(int i=0; i<currlen; i++){
            temp[i] = st[curr+i];
        }
        temp[currlen] = '\0';

        int res = ispalindrome(temp);
        free(temp);
        if(res) return currlen;
        curr++;
    }

    return help(st, start, end, totlen, currlen-1);
}

//returns the length of the longest palindrome in string st
int longestpalindrome(char* st, int start, int end){
    int len = strlen(st);
    return help(st, start, end, len, len);
}

int main(void){
    assert(6==longestpalindrome("111111",0,5));
    assert(7==longestpalindrome("abbbcxyzazyxbba",0,14));
    assert(1==longestpalindrome("a",0,0));
    assert(6==longestpalindrome("aaa77777jbbbbbboh666aaa",0,23));
    assert(6==longestpalindrome("abccbacba",0,8));
    printf("passed\n");

    return 0;
}