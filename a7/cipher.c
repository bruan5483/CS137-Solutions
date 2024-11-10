#include <stdio.h>
#include <string.h>
 
// Function to reverse the entire string
void reverseString(char *str) {
    
}
 
// Function to replace each vowel with the next consonant
void replaceVowels(char *str) {
    
}
 
// Function to shift each consonant to the right by a number of positions
// equal to its ASCII value modulo 10
void shiftConsonants(char *str) {
   
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