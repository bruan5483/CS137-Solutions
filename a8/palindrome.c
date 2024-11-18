#include <stdio.h>
 
// Function to check if it is possible to rearrange the characters to form a palindrome
void canFormPalindrome(char *str) {
    int arr[26] = {0};
    int i = 0;
    int num_odd = 0;
    while(str[i]!='\0'){
        arr[str[i]-97]++;
        if(arr[str[i]-97]%2 != 0) num_odd++;
        else num_odd--;
        i++;
    }
    if (num_odd>1) printf("NO\n");
    else printf("YES\n");
    return;
}
 
//Do not change this part for testing. Do not submit it.
int main() {
    char inputString[1001];  // you can make it bigger if you want to test longer strings
 
    // Read the input string
    printf("Enter a string of lowercase characters: ");
    scanf("%1000s", inputString);
 
    // Check if it is possible to rearrange the characters to form a palindrome
    canFormPalindrome(inputString);
 
    return 0;
}
