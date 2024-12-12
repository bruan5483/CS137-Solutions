//Write a function that takes a string (s1) allocated on the heap and integer n 
//and returns a new string similar to s1 repeated n times  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repeat(char *s1, int n){
    int len = strlen(s1);
    int newlen = 3*len;
    char *ret = malloc((newlen+1)*sizeof(char));

    for(int i = 0; i<newlen; i++){
        ret[i] = s1[i%len];
    }

    ret[newlen] = '\0';
    return ret;
}

int main(void){
    char *a = malloc(4*sizeof(char));
    a[0]='a';
    a[1]='b';
    a[2]='c';
    a[3]='\0';

    //repeat("abc", 3) => "abcabcabc"
    char *b = repeat(a, 3);
    printf("%s\n",b);

    free(a);
    free(b);
}