#include <assert.h>
#include <stdio.h>

 //finds the number of diigits in n
int numDigits(long long int n){
    int counter = 1;
    while (n/10!=0){
        n/=10;
        counter++;
    }
    return counter;
}

int removekdigits(long long int n, int k){
    int len = numDigits(n);
    
    //if all digits are deleted or n=0
    if (len == k || n == 0) return 0;

    int a[10] = {0};

    for (int i = 0; i<len; i++){
        int dig = n % 10;
        a[dig]++;
        n /= 10;
    }

    int small = 0;
    int s_index = 0;
    for (int j=0; j<(len-k); j++){
        while(a[s_index]==0) s_index++;
        small = 10*small + s_index;
        a[s_index]--;
    }
    return small;

}
/*
int main(void) {
    //printf("%d\n", removekdigits(12345678990,3));
    assert(removekdigits(345267, 3) == 234);
    assert(removekdigits(0, 0) == 0);
    assert(removekdigits(9, 1) == 0);
    assert(removekdigits(871, 0) == 178);
    assert(removekdigits(9898989, 2) == 88899);
    assert(removekdigits(12345, 2) == 123);
    assert(removekdigits(54321, 1) == 1234);
    assert(removekdigits(11111, 2) == 111);
    assert(removekdigits(987654, 4) == 45);
    assert(removekdigits(10203, 1) == 12);
    assert(removekdigits(7654321, 5) == 12);
    assert(removekdigits(987654321, 4) == 12345);
    assert(removekdigits(567890, 2) == 567);
    assert(removekdigits(24680, 3) == 2);
    assert(removekdigits(1234567890, 5) == 1234);
    assert(removekdigits(999999999, 8) == 9);
    assert(removekdigits(987, 3) == 0);
    assert(removekdigits(111222333, 6) == 111); 
    assert(removekdigits(10000, 3) == 0);
    assert(removekdigits(70005, 2) == 0);
    assert(removekdigits(1023, 1) == 12);

    printf("Done\n");
    return 0;
}
*/