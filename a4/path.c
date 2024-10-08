#include <stdio.h>
#include <assert.h>

//helper recursive function, passing in extra params for position in matrix
int pos(int m, int n, int a[m][n], int pos_x, int pos_y){
    if (pos_x==m-1 && pos_y == n-1) return 1; 
    else if (a[pos_x+1][pos_y] == 1 && a[pos_x][pos_y+1]==1){
        return pos(m, n, a, pos_x+1, pos_y)+pos(m, n, a, pos_x, pos_y+1);
    } else if (a[pos_x+1][pos_y] == 1){
        return pos(m, n, a, pos_x+1, pos_y);
    } else if (a[pos_x][pos_y+1] == 1){
        return pos(m, n, a, pos_x, pos_y+1);
    } else return 0;
}

int monotonePath(int m, int n, int a[m][n]){
    int paths = pos(m, n, a, 0, 0);
    if (paths > 0) return 1;
    return 0;
}

/*
int main(void)
{
    int m = 10;
    int n = 12;
    int a[][12] = {{1,1,0,0,0,0,0,0,0,0,0,0},
                   {0,1,1,0,0,0,0,0,0,0,0,0},
                   {0,0,1,1,1,1,0,0,0,0,0,0},
                   {0,0,1,0,0,1,0,0,0,0,0,0},
                   {0,1,1,0,0,1,1,0,0,0,0,0},
                   {0,1,0,0,0,0,1,0,0,0,0,0},
                   {0,1,1,0,0,0,1,1,1,0,0,0},
                   {0,0,1,0,0,0,0,0,1,0,0,0},
                   {0,0,1,1,1,1,1,1,1,1,1,0},
                   {0,0,0,0,0,0,0,0,0,0,1,1}
    };
    
    // a, but with one entry switched eliminating the monotone path
    int b[10][12] = {{1,1,0,0,0,0,0,0,0,0,0,0},
                     {0,1,1,0,0,0,0,0,0,0,0,0},
                     {0,0,1,1,0,1,0,0,0,0,0,0},
                     {0,0,1,0,0,1,0,0,0,0,0,0},
                     {0,1,1,0,0,1,1,0,0,0,0,0},
                     {0,1,0,0,0,0,1,0,0,0,0,0},
                     {0,1,1,0,0,0,1,1,1,0,0,0},
                     {0,0,1,0,0,0,0,0,1,0,0,0},
                     {0,0,1,1,1,1,1,1,1,1,1,0},
                     {0,0,0,0,0,0,0,0,0,0,1,1}
    };

    int c[10][12] = {{1,1,0,0,0,0,0,0,0,0,0,0},
                     {0,1,1,0,0,0,0,0,0,0,0,0},
                     {0,0,1,1,1,1,0,0,0,0,0,0},
                     {0,0,1,0,0,1,0,0,0,0,0,0},
                     {0,0,1,1,0,1,1,0,0,0,0,0},
                     {0,0,0,1,0,0,1,0,0,0,0,0},
                     {0,0,0,1,0,0,1,1,1,0,0,0},
                     {0,0,0,1,0,0,0,0,1,0,0,0},
                     {0,0,0,1,1,1,1,1,1,1,1,0},
                     {0,0,0,0,0,0,0,0,0,0,1,1}
    };
    
    
    assert (monotonePath(m, n, a));
    assert (!monotonePath(m, n, b));
    assert (monotonePath(m, n, c));
    printf("Done!\n");

    return 0;
}
*/