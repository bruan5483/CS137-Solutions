#include <stdio.h>

//prints num spaces
void spaces(int num, int curr){
    if (num < curr) return;
    if (num==curr) {
        printf(" ");
        return;
    }
    printf(" ");
    spaces(num, curr+1);
    return;
}

//prints num pluses
void plus(int num, int curr){
    if (num<curr) return;
    if (num==curr) {
        printf("+");
        return;
    }
    printf("+");
    plus(num, curr+1);
    return;

}

//prints the trunk of the tree
void trunk(int n, int curr, int width){
    if (curr==2*n+1) {
        printf(".");
        return;
    } else if (curr==1){
        printf(".");
        trunk(n, curr+1, width);
    } else if (width==1){
        spaces(n-1,1);
        printf("|");
        spaces(n-1,1);
        trunk(n, curr+2*n-1, width);
    } else {
        spaces((2*n-1-width)/2,1);
        printf("|");
        spaces(width-2,1);
        printf("|");
        spaces((2*n-1-width)/2,1);
        trunk(n, curr+2*n-1, width);
    }
    return;
}

//prints the tree
void tre(int n, int row, int width){
    if (row == 1){
        printf(".");
        spaces(n-row,1);
        printf("*");
        spaces(n-row,1);
        printf(".");
    } else if (row < n+1) {
        printf(".");
        spaces(n-row,1);
        printf("+");
        spaces(1+2*(row-2),1);
        printf("+");
        spaces(n-row,1);
        printf(".");
    } else if (row == n+1) {
        printf("*");
        plus(2*n-1,1);
        printf("*");
    } else if (row <= 2*n+1){
        trunk(n, 1, width);
        if (row==2*n+1) return;
    }

    printf("\n");
    tre(n, row+1, width);
    return;

}

//required function calls helper function
void tree(int n){
    int width;
    if (n%2==0)width = n/2; 
    else width = (n+1)/2;
    if (width % 2 == 0) width++;

    tre(n, 1, width);
    return;
}

/*
int main(void){
    tree(20);
    printf("\n");
    return 0;
}
*/