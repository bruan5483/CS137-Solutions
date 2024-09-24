#include <stdio.h>
int main (void) {
    int num, denom;
    scanf("%d %d", &num, &denom);

    if (num % denom == 0){
        printf("%d\n",num/denom);
    }else if((num > 0 && denom > 0)||(num < 0 && denom < 0)){
        printf("%d\n", num/denom + 1);
    } else if (num==0){
        printf("0");
    } else {
        printf("%d\n", num/denom - 1);
    }

    return 0;
}