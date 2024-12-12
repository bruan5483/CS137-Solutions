//implement binary search recursively

#include <stdio.h>

//returns index of target
int binary_search(int a[], int len, int target){

    int middle = len/2;

    if (a[middle] == target) return middle;
    //if not found and last element return -1
    if (len <= 1) return -1;
    
    if (a[middle]<target) {
        int result = binary_search(&a[middle+1],len-middle-1,target);
        return result == -1 ? -1 : middle + 1 + result;
    }
    else return binary_search(a, middle, target);
}

int main(void){
    int a[] = {0,1,2,3,4,5,6,7,8,9,11};
    printf("%d\n",binary_search(a,11,-1));
    printf("%d\n",binary_search(a,11,3));
    printf("%d\n",binary_search(a,11,9));
    printf("%d\n",binary_search(a,11,5));
    printf("%d\n",binary_search(a,11,1000));
    printf("%d\n",binary_search(a,11,10));
}