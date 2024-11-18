#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int count_common(long long int a[], long long int n1, long long int b[], long long int n2){
    long long int i = 0, j = 0;
    int count = 0;
    while(i < n1 && j < n2){
        if(a[i]==b[j]){
            count++;
            long long int current = a[i];
            while (i < n1 && a[i] == current) i++;
            while (j < n2 && b[j] == current) j++;
        }else if(a[i]>b[j]){
            j++;
        }else if (a[i]<b[j]){
            i++;
        }
    }
    return count;
}


int main(void){
    long long int a1[4] = {1,1,1,1};
    long long int b1[8] = {1,1,1,1,1,1,1,1};
    assert(1 == count_common(a1,4,b1,8));

    long long int a2[8] = {1,3,3,4,5,8,9,100};
    long long int b2[7] = {4,4,8,15,20,40,100};
    assert(3 == count_common(a2,8,b2,7));

    long long int a3[3] = {1, 3, 5};
    long long int b3[3] = {2, 4, 6};
    assert(0 == count_common(a3, 3, b3, 3));

    long long int a4[3] = {1, 3, 5};
    long long int b4[3] = {3, 5, 7};
    assert(2 == count_common(a4, 3, b4, 3));

    long long int a5[5] = {1, 2, 3, 4, 5};
    long long int b5[3] = {2, 3, 4};
    assert(3 == count_common(a5, 5, b5, 3));

    long long int a6[6] = {1, 1, 2, 3, 3, 3};
    long long int b6[4] = {1, 3, 3, 4};
    assert(2 == count_common(a6, 6, b6, 4));

    long long int a7[3] = {1, 2, 3};
    long long int b7[3] = {4, 5, 6};
    assert(0 == count_common(a7, 3, b7, 3));

    long long int a8a[0] = {};
    long long int b8a[3] = {1, 2, 3};
    assert(0 == count_common(a8a, 0, b8a, 3));

    long long int a8b[3] = {1, 2, 3};
    long long int b8b[0] = {};
    assert(0 == count_common(a8b, 3, b8b, 0));

    long long int a9[0] = {};
    long long int b9[0] = {};
    assert(0 == count_common(a9, 0, b9, 0));

    long long int a10[5] = {1, 2, 3, 4, 5};
    long long int b10[5] = {1, 2, 3, 4, 5};
    assert(5 == count_common(a10, 5, b10, 5));

    long long int a11[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    long long int b11[6] = {5, 6, 7, 8, 9, 10};
    assert(4 == count_common(a11, 8, b11, 6));

    long long int a12[5] = {1, 3, 5, 7, 9};
    long long int b12[9] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    assert(0 == count_common(a12, 5, b12, 9));

    long long int a13[10] = {
        1000000000000000001LL, 
        1000000000000000002LL, 
        1000000000000000003LL, 
        1000000000000000004LL, 
        1000000000000000005LL, 
        1000000000000000006LL, 
        1000000000000000007LL, 
        1000000000000000008LL, 
        1000000000000000009LL, 
        1000000000000000010LL
    };
    long long int b13[8] = {
        1000000000000000003LL, 
        1000000000000000005LL, 
        1000000000000000007LL, 
        1000000000000000009LL, 
        1000000000000000011LL, 
        1000000000000000013LL, 
        1000000000000000015LL, 
        1000000000000000017LL
    };
    assert(4 == count_common(a13, 10, b13, 8));

    // Very long test case
    long long int *a14 = (long long int *)malloc(10000 * sizeof(long long int));
    long long int *b14 = (long long int *)malloc(5000 * sizeof(long long int));

    if (a14 == NULL || b14 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Fill `a` with even numbers starting from 10^18
    for (long long int i = 0; i < 10000; i++) {
        a14[i] = 1000000000000000000LL + i * 2;
    }

    // Fill `b` with every third even number starting from 10^18
    for (long long int i = 0; i < 5000; i++) {
        b14[i] = 1000000000000000000LL + i * 6;
    }

    // Calculate the expected count of common elements
    int expected_count = 0;
    for (long long int i = 0; i < 5000; i++) {
        if ((b14[i] - 1000000000000000000LL) % 2 == 0 &&
            (b14[i] - 1000000000000000000LL) / 2 < 10000) {
            expected_count++;
        }
    }

    // Assert the function produces the correct result
    assert(expected_count == count_common(a14, 10000, b14, 5000));

    printf("Test passed with %d common elements.\n", expected_count);

    // Free allocated memory
    free(a14);
    free(b14);
   
    return 0;
}