#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

//finds number of digits in a number
int numDigits(int n, int digits){
    if (n/10 == 0) return digits+1;
    return numDigits(n/10, digits+1);
}

//raises n to the power of degree
int power(int n, int curr, int degree, int count){
    if (count == degree) return curr;
    return power(n,curr*n,degree,count+1);
}

//helper function summing each digit to the power of the number of digits
int narc(int n, int sum, int digits){
    if (n/10 == 0) {
        return sum + power(n,1,digits,0);}
    return narc(n/10, sum + power(n%10,1,digits,0), digits);
}

//required function implements helper functions
bool narcissist(int n){
    int digits = numDigits(n, 0);
    if (narc(n,0,digits) == n) return true;
    return false;
}

/*
int main(void){
    //printf("%d\n",narc(153,0,3));
    
    assert(narcissist(1));
    assert(narcissist(9));
    assert(narcissist(153));
    assert(narcissist(370));
    assert(narcissist(92727));
    assert(narcissist(548834));
    assert(!narcissist(10));
    assert(!narcissist(92));
    assert(!narcissist(1535));
    assert(!narcissist(1234));
    assert(!narcissist(92726));
    assert(!narcissist(93083));
    
    return 0;
}
*/