#include <stdio.h>
#include <math.h>
#include <assert.h>

#define PI acos(-1)
/*
double f1(double x){
	return x*x;
}

double f2(double x){
	return cos(x);
}

double f3(double x){
	return sqrt(x);
}
*/

double area(double (*f)(double), double a, double b, int n){
	double delta = (b-a)/n;
	double area = 0;

	for (int i = 0; i < n; i++){
		area += (0.5*(f(a+(i*delta))+f(a+((i+1)*delta)))*delta);
	}
	//printf("%f\n",area);
	return area;
}


double trapezoidal(double (*f)(double), double a, double b, double epsilon, int n){

	double prev = area(f, a, b, n);
	double curr = area(f, a, b, 2*n);
	int iterations = 2;

	//printf("prev: %f curr: %f\n", prev, curr);
	
	while(fabs(curr-prev)>epsilon){
		prev = curr;
		curr = area(f, a, b, pow(2,iterations)*n);
		iterations++;
		//printf("prev: %f curr: %f\n", prev, curr);
	}
	
	return curr;
}

/*
int main(void){
	//trapezoidal(f1, 5, 10, 0.00001, 2);
  	assert(fabs(trapezoidal(f1, 5, 10, 0.00001, 2) - 291.667) <= 0.001);
	assert(fabs(trapezoidal(f2, PI / 2, 3, 0.00001, 5) - -0.858879) <= 0.000001);
	assert(fabs(trapezoidal(f3, 1, 4, 0.00001, 2) - 4.666) <= 0.001);
	printf("done\n");
  	return 0;
}
*/