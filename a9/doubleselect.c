#include <stdio.h>

//Do not change it.
void printarr(int a[], int len){
    for (int i=0; i<len-1; i++)
       printf("%d ", a[i]);
    printf("%d\n", a[len-1]);
}

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return;
}


void help(int a[], int len, int og[], int og_len){
    if (len<2) return;
    int min = a[0], max = a[0];
    int min_i = 0, max_i = 0;
    for (int i=1; i<len; i++){
        if (min > a[i]){
            min = a[i];
            min_i = i;
        }
        if (max < a[i]){
            max = a[i];
            max_i = i;
        }
    }

    swap(a, 0, min_i);
    if(max_i == 0) swap(a, len-1, min_i);
    else swap(a, len-1, max_i);

    printarr(og, og_len);
    help(&a[1], len-2, og, og_len);

}

void doubleselectionsort(int a[], int len){
    help(a, len, a, len);
}

int main(void) {
   
    int a[7] = {4, 4, 4, 0, 0, -10, -10};
    doubleselectionsort(a,7);
    int a2[5] = {6, 11, 2, -4, -1};
    doubleselectionsort(a2,5);
    int a3[10] = {1, 8, 5, 4, 6, 2, 5, 6, 2, 9};
    doubleselectionsort(a3,10);

    int a4[8] = {1, 4, 3, 6, 5, 7, 2, 8};
    doubleselectionsort(a4,8);
    
    return 0;
}
