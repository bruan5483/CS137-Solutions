#include <stdio.h>

//helper recursive function with an extra param checking for duplicates
void numP(int full_num, int prev){
    //number has no digits left (innermost loop)
    //innermost loop prints if first digit is a non-repeated digit before returning
    if (full_num/10 == 0 && full_num % 10 != prev) {
        printf("%d%d", full_num, full_num);
        return;
    
    //if the first digit is a duplicate we don't print
    } else if (full_num/10 == 0) {
        return;

    //check if digit is the same as the previous
    //skip printing if number is a duplicate
    } else if (full_num % 10 == prev){
        numP(full_num/10, prev);

    //unique digit makes next recursive call first
    //then prints its digit on the way out
    } else {
        numP(full_num/10, full_num%10);
        printf("%d%d", full_num%10, full_num%10);
    }
    return;
}

//function satisfying requirements
void numberPairs(int n){
    //call helper function with a non-digit int (i.e. 10)
    numP(n, 10);
    return;
}

/*
int main(void){
    numberPairs(1234);
    printf("\n");
    numberPairs(338888886);
    printf("\n");
    numberPairs(555555555);
    printf("\n");
    numberPairs(1);
    printf("\n");
    return 0;
}
*/