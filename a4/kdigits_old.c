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

    //all digits are removed
    if (len == k || n == 0) return 0;

    //initialize and fill array with all digits of n
    int a[len];
    for (int i = 0; i<len; i++){
        a[i] = n % 10;
        n /= 10;
    }

    int small = 0;
    for (int j=0; j<(len-k); j++){
        int smallest = 10, small_index = 0;
        for (int i=0; i<len; i++){
            if (a[i]!=10 && smallest > a[i]){
                if (j==0 && a[i]==0){
                    continue;
                } else {
                smallest = a[i];
                small_index = i;
                }
            }
        }
        small = 10*small + smallest;
        
        a[small_index] = 10;
    }
   return small;
} 

int main(void) {
    //printf("%d\n", removekdigits(12345678990,3));
    assert(removekdigits(345267,3)==234);
    assert(removekdigits(0,0)==0);
    assert(removekdigits(9,1)==0);
    assert(removekdigits(871,0)==178);
    assert(removekdigits(9898989,2)==88899);
    printf("Done\n");
    return 0;
}
