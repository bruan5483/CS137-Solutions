//Write a function that takes a string (s1) allocated on the heap and returns a new string similar to s1 but reversed.

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char * reverse(char s1[]){
    int len = strlen(s1);
    int i = 0;
    char *ret = malloc((len+1)*sizeof(char));
    while(s1[i]){
        ret[len-1-i] = s1[i];
        i++;
    }
    ret[len] = '\0';
    return ret;
}

int main(void){
    char *a = malloc(6*sizeof(char));
    a[0] = 'H';
    a[1] = 'e';
    a[2] = 'l';
    a[3] = 'l';
    a[4] = 'o';
    a[5] = '\0';

    char *b = reverse(a);
    printf("%s\n", b);

    free(a);
    free(b);

}