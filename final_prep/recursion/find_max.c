//define a recursive function that takes an array and its size and return the maximal value

#include <stdio.h>

int helper_max(int *a, int len, int curr_max){
    if (*a > curr_max) curr_max = *a;

    if (len <= 1) return curr_max;
    else return helper_max(a+1,len-1,curr_max);
}

//pre: len > 0
int find_max(int a[], int len){
    if (len==1) return a[0];
    return helper_max(a+1, len-1, a[0]);
}

int main(void){
    int a[] = {7,3,1,6,8,10,20,4,1,0};
    printf("max: %d\n", find_max(a,sizeof(a)/sizeof(int)));

    int b[] = {11};
    printf("max: %d\n", find_max(b,sizeof(b)/sizeof(int)));

}