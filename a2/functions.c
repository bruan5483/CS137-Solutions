#include <stdio.h>
#include "functions.h"

void square(int w){
    int count = 1;
    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= w; j++){
            printf("%d ", count);
            count++;
        }
        printf("\n");
    }
}

void spiral(int w){
    int outer = w;
    //direction of print; 0=right, 1=down, 2=left, 3=up
    int dir = 0;
    int num = 1;
    for (int i = 1; i <= (w*w); i++){
        if (dir == 0){
            for (int j = 1; j<=outer; j++){
                printf("%d ", num);
                if (j==outer){
                    dir = 1;
                    num += w;
                } else num++;
            }
        } else if (dir == 1){
            for (int j = 2; j<=outer; j++){
                printf("%d ", num);
                if (j==outer){
                    dir = 2;
                    num -= 1;
                } else num += w;
            }

        } else if (dir == 2){
            for (int j = 2; j<=outer; j++){
                printf("%d ", num);
                if (j==outer){
                    dir = 3;
                    num -= w;
                } else num -= 1;
            }

        } else if (dir == 3){
            for (int j = 2; j<=outer-1; j++){
                printf("%d ", num);
                if (j==outer-1){
                    dir = 0;
                    num += 1;
                    outer -= 2;
                } else num -= w;
            }
        }
    }
    printf("\n");
}

void rotation(int w){
    int outside = 0;
    int num = 1;
    //tracking current corner; t_left=0, t_right=1, b_right=2, b_left=3
    int place = 0;

    //tracking current loop
    int loop_num = 1;

    for (int i = 1; i <= (w*w); i++){
        //print current number
        printf("%d ", num);

        //set up next number
        if (place == 0){
            num += (((w-1)*(loop_num))-(2*outside));
            //next number in t_right
            place++;
        } else if(place == 1){
            num = (((w*w)-(outside*(w+1))) - loop_num + 1);
            //next number in b_right
            place++;
        } else if(place == 2){
            num -= (((w-1)*(loop_num))-(2*outside));
            //next number in b_left
            place++;
        } else if(place == 3){
            //next number in t_left
            place = 0;

            //check if reached 2nd last in outermost layer
            if(loop_num == w-1-(2*outside)){
                loop_num = 1;
                outside++;
                num++;
            } else {
                num = 1 + (outside*(w+1)) + loop_num;
                loop_num++;
            }
        }
    }
    printf("\n");
}