// Write a recursive function to rotate an array of integers to the right by k positions.

#include <stdio.h>
#include <stdlib.h>

void helper(int a[], int len, int k, int new[], int curr){
    if (curr == len) return;

    int new_pos = (curr+k) % len;
    new[new_pos] = a[curr];
    helper(a,len,k,new,curr+1);
    return;
}

//pre: len>0
int* rotateArray(int a[], int len, int k){
    int *new = malloc(len*sizeof(int));
    helper(a, len, k , new, 0);    
    return new;

}

int main(void){
    int a[] = {1,2,3,4,5};
    int *b = rotateArray(a, 5, 2);
    for(int i=0; i<5; i++) printf("%d ",b[i]);
    printf("\n");
    
    free(b);

}