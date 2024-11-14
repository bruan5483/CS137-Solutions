#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

char* merge(char* s1, char* s2) {
    char* s3 = malloc(((strlen(s1)+strlen(s2))+2)*sizeof(char));
    int curr_i2 = 0;
    int curr_i3 = 0;
    for(int i = 0; i<strlen(s1); i++){
        if(s1[i] == ' '){
            if (curr_i2<strlen(s2)) {
                s3[curr_i3] = ' ';
                curr_i3++;
            }
            while (s2[curr_i2] != ' ' && curr_i2<strlen(s2)){
                s3[curr_i3] = s2[curr_i2];
                curr_i3++;
                curr_i2++;
            }
            if (s2[curr_i2] == ' ') curr_i2++;;
        }

        s3[curr_i3] = s1[i];
        curr_i3++;
    }

    if (curr_i2<strlen(s2)){
        s3[curr_i3] = ' ';
        curr_i3++;
    }

    while (curr_i2<strlen(s2)){
        s3[curr_i3] = s2[curr_i2];
        curr_i3++;
        curr_i2++;
    }

    s3[curr_i3] = '\0';

    return s3;
}
/*
int main(void){
        
    char s1[] = "The brown jumps the dog";
    char s2[] = "quick fox over lazy";
    char *s = merge(s1, s2);
    assert(!strcmp(s, "The quick brown fox jumps over the lazy dog"));
    free(s);
    
    char s3[] = "the brown";
    char s4[] = "quick fox is sleeping today";  
    s = merge(s3,s4);
    assert(!strcmp(s, "the quick brown fox is sleeping today"));
    free(s);
    
    char* s5 = "happy to you";
    char* s6 = "birthday";  
    s = merge(s5,s6);
    assert(!strcmp(s, "happy birthday to you"));
    free(s);

    return 0;
}
*/