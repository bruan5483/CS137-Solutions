#include <stdio.h>
#include <math.h>

double average(int a[]){
    int sum = 0;
    int n_stu = 0;
    for (int i=0; i<101; i++){
        sum += (i*a[i]);
        n_stu += a[i];
    }
    return (double)sum/n_stu;
}

double stDev(int a[], double mean){
    double sigma = 0;
    int n_stu = 0;
    for (int i=0; i<101; i++){
        sigma += (a[i]*(pow(i-mean,2.0)));
        n_stu += a[i];
    }
    return sqrt(sigma/(n_stu-1));
}

void grades(){

    int grade;
    int grades[101] = {0};

    while(scanf("%d",&grade)) grades[grade]++;
    
    int max = 0, num_max = 0; 
    int min = 100, num_min = 0, min_found = 0;
    for(int i = 0; i<101; i++){
        if (grades[i]>0){
            max = i;
            num_max = grades[i];
        }
        if(min_found !=1 && grades[i]>0){
            min = i;
            num_min = grades[i];
            min_found = 1;
        }
    }

    int failed = 0;
    for(int i=0; i<50;i++){
        failed += grades[i];
    }

    double av = average(grades);

    printf("The maximal grade is: %d\n", max);
    printf("The number of students who received the maximal grade is %d\n", num_max);
    printf("The minimal grade is: %d\n", min);
    printf("The number of students who received the minimal grade is %d\n", num_min);
    printf("The course mean is: %0.3f\n", av);
    printf("The standard deviation is: %0.3f\n", stDev(grades, av));
    printf("The number of students who failed the course is: %d\n", failed);

    return;
}


int main(void){
    grades();
    return 0; 
}