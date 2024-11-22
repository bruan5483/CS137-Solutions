#include <stdlib.h>
#include <assert.h>

// O(n) sorting (O(n)+O(n)=O(n))
// See https://www.w3schools.com/dsa/dsa_algo_countingsort.php for proof
void sort(long long a[], int n){
    // frequency array
    long long int *temp = calloc(n+1,sizeof(long long int));
    for(int i=0; i<n; i++) temp[a[i]]++; // O(n)

    int a_ind = 0;
    for(int j=0; j<n+1; j++){ // O(n+n+1) = O(n)
        while(temp[j]>0){
            a[a_ind]=j;
            a_ind++;
            temp[j]--;
        }
    }
    free(temp);
}

// Overall O(n) since O(n)+O(n) = O(n)
long long int multiadd(long long int a[], int n){
    sort(a,n); // O(n) 
    // log_2n steps; each step taking O(n/2^k) where k is # of multi and add steps
    // sum from k=1 to log_2n of n/2^k is n
    // therefore the following loop is O(n)
    while(n>1){ 
        n/=2;
        
        // multiply step O(n/2^k)
        for(int i = 0; i<n; i++){
            a[i]=a[2*i]*a[2*i+1];
        }
        if (n==1) break;
        n/=2;

        // add step O(n/2^k)
        for(int i = 0; i<n; i++){
            a[i]=a[2*i]+a[2*i+1];
        }
    }

    return a[0];
}


int main(void){
    long long int a[8] = {1,4,3,6,5,3,2,8};
    assert(748 == multiadd(a,8));

    long long int b[16] = {0};
    assert(0 == multiadd(b,16));

    long long int c[16] = {1,6,5,8,6,7,5,4,8,9,10,2,12,14,1,1};
    assert(27498 == multiadd(c,16));

    long long int d[2] = {5, 10};
    assert(50 == multiadd(d, 2));

    long long int e[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    assert(4 == multiadd(e, 8));

    long long int f[8] = {8, 8, 8, 8, 8, 8, 8, 8};
    assert(16384 == multiadd(f, 8));

    long long int g[32] = {28, 0, 11, 0, 4, 0, 18, 23, 22, 1, 24, 20, 2, 14, 30, 17, 0, 32, 8, 14, 7, 20, 18, 27, 7, 10, 14, 6, 30, 30, 12, 9};
    assert(95346238240 == multiadd(g, 32));

    long long int h[32] = {27, 31, 19, 18, 25, 4, 30, 19, 30, 22, 12, 17, 24, 26, 17, 1, 14, 5, 23, 8, 7, 16, 19, 15, 22, 27, 11, 5, 10, 31, 18, 4};
    assert(660361857372 == multiadd(h, 32));

    return 0;
}