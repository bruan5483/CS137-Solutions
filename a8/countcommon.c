// #include ....


int count_common(long long int a[], long long int n1, long long int b[], long long int n2){
    
}


int main(void){
    long long int a1[4] = {1,1,1,1};
    long long int b1[8] = {1,1,1,1,1,1,1,1};
    assert(1 == count_common(a1,4,b1,8));
    long long int a2[8] = {1,3,3,4,5,8,9,100};
    long long int b2[7] = {4,4,8,15,20,40,100};
    assert(3 == count_common(a2,8,b2,7));
   
    return 0;
}