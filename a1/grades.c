#include <stdio.h>
int main(void){
    int q, a, m;
    scanf("%d %d %d", &q, &a, &m);

    int needed_1 = (50 - 0.05*q - 0.2*a - 0.3*m)/0.45;
    int needed_2 = (37.5 - 0.3*m)/0.45;

    if (needed_1 >= needed_2){
        printf("%d", needed_1);
    } else printf("%d", needed_2);

    return 0;
}