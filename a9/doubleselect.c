// #include ...


//Do not change it.
void printarr(int a[], int len){
    for (int i=0; i<len-1; i++)
       printf("%d ", a[i]);
    printf("%d\n", a[len-1]);
}

void doubleselectionsort(int a[], int len){
    
}

int main(void) {
   
    int a[7] = {4, 4, 4, 0, 0, -10, -10};
    doubleselectionsort(a,7);
    int a2[5] = {6, 11, 2, -4, -1};
    doubleselectionsort(a2,5);
    int a3[10] = {1, 8, 5, 4, 6, 2, 5, 6, 2, 9};
    doubleselectionsort(a3,10);
    
    return 0;
}
