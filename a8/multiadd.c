// #include ....


long long int multiadd(long long int a[], int n){

}


int main(void){
    long long int a[8] = {1,4,3,6,5,3,2,8};
    assert(748 == multiadd(a,8));
    long long int b[16] = {0};
    assert(0 == multiadd(b,16));
    long long int c[16] = {1,6,5,8,6,7,5,4,8,9,10,2,12,14,1,1};
    assert(27498 == multiadd(c,16));
    
    return 0;
}