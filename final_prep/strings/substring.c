//Write a function that takes two strings s1 and s2, returns true if s1 is a substring of s2, otherwise false.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool substring(char* s1, char* s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int curr = 0;
    while(curr + len1 <= len2){
        char *temp = malloc((len1+1)*sizeof(char));
        for(int i=0; i<len1; i++){
            temp[i] = s2[curr+i];
        }
        temp[len1] = '\0';
        //printf("%s\n", temp);
        int res = strcmp(temp, s1);
        free(temp);
        if(res==0) return true;
        curr++;
    }

    return false;

}

int main(void){
    char a[] = "test";
    char b[] = "nokjntestweq";
    char c[] = "asldknaldjna";

    printf("%d\n", substring(a,b));
    printf("%d\n", substring(a,c));

}