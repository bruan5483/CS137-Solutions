#include <stdio.h>
#include <string.h>
 
// Function to reverse the entire string
void reverseString(char *str) {
    for(int i = 0; i<(strlen(str)+1)/2; i++){
        char temp = str[strlen(str)-1-i];
        str[strlen(str)-1-i] = str[i];
        str[i] = temp;
    }
    return;
}
 
// Function to replace each vowel with the next consonant
void replaceVowels(char *str) {
    for(int i=0; i<strlen(str);i++){
        if(str[i] == 'A') str[i] = 'B';
        else if (str[i] == 'E') str[i] = 'F';
        else if (str[i] == 'I') str[i] = 'J';
        else if (str[i] == 'O') str[i] = 'P';
        else if (str[i] == 'U') str[i] = 'B';
    }
    return;
}
 
// Function to shift each consonant to the right by a number of positions
// equal to its ASCII value modulo 10
void shiftConsonants(char *str) {
    for(int i=0; i<strlen(str);i++){
        if(str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U' && str[i] != ' '){
            int shift = str[i] % 10;
            str[i] += shift;
            if(str[i]>90) str[i] -= 26;
        }
    }
    return;
}


 // DO NOT CHANGE MAIN
int main(void) {
    char inputString[101];
 
    // Read the input string
    printf("Enter a string (uppercase letters and spaces only): ");

   scanf("%100[^\n]s", inputString);
   
    // Reverse the entire string
    reverseString(inputString);
    printf("Reversed String: %s\n", inputString);
    
    // Replace vowels with the next consonant
    replaceVowels(inputString);
    printf("Replaced Vowels String: %s\n", inputString);
    
    // Shift consonants to the right
    shiftConsonants(inputString);
    // Print the final result
    printf("Ciphered String: %s\n", inputString);
 
    return 0;
}