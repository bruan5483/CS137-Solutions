#include <stdio.h>
int main(void){
    int spaces; 
    int length = 2, head_pos = 3;
    //input
    scanf("%d", &spaces);

    //while snake head is not at the end
    while(head_pos <= (spaces - 1)){
        //snake on user provided number of spaces
        for(int i = 0; i <= (spaces - 1); i++){
            
            if(i == head_pos){
                printf("H");
            
            } else if((i<head_pos) && (i>=(head_pos-length))){
                printf("X");
                
            } else if((i%2!=0) && (i>head_pos)){
                printf(".");
            } else {
                printf("_");
            }
        }
        //new line
        printf("\n");

        //increment where head of snake it
        head_pos++;

        //check if snake consumed bait
        if(head_pos % 2 != 0 && head_pos > 3){
            length++;
        }
    }
    return 0;
}