#include <stdio.h>
#include "fun.h"

int isSophieGermainPrime(int p){
    if (p > 1 && (p % 2 != 0 || p == 2)){
        for (int i = 3; i < p; i+=2){
            if (p % i == 0) return 0;
        }
        for (int j = 3; j < (2*p)+1; j+=2){
            if (((2*p)+1) % j == 0) return 0;
        }
        return 1;
    } else return 0;
}

int base2nat(int bs, int num){
    int dec_num = 0;
    int conv = 1;
    while (num>0){
        dec_num += ((num % 10)*conv);
        conv *= bs;
        num /= 10;
    }
    return dec_num;
}

int nat2base(int bs, int num){
    int bs_num = 0;
    int conv = 1;
    while (num>0){
        bs_num += (num % bs)*conv;
        conv *= 10;
        num /= bs;
    }
    return bs_num;
}

/*
int main(void){
    printf("%d\n", isSophieGermainPrime(1000004249));
    printf("%d\n", isSophieGermainPrime(-7));
    printf("%d\n", base2nat(8,715));
    printf("%d\n", nat2base(9,1331));
    return 0;
}
//Large Sophie Germain Prime 1000004249
*/