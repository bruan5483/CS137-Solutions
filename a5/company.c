#include <stdio.h>


#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    int age;
    double salary;
};

void inputEmployees(struct Employee employees[], int n) {
    printf("Enter the details of %d employees:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Age: ");
        scanf("%d", &employees[i].age);
        printf("Salary: ");
        scanf("%lf", &employees[i].salary);
    }
}

void displayEmployees(struct Employee employees[], int n) {
    printf("Employee Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("ID: %d\n", employees[i].id);
        printf("Age: %d\n", employees[i].age);
        printf("Salary: %.2lf\n", employees[i].salary);
    }
}

double averageSalary(struct Employee employees[], int n) {
    double tot = 0;
    for(int i = 0; i < n; i++) tot += employees[i].salary;
    return tot/n;
}

void youngestEmployee(struct Employee employees[], int n) {
    int lowAge = employees[0].age;
    int lowInd = 0;
    for(int i = 1; i<n; i++){
        if (employees[i].age < lowAge){
            lowAge = employees[i].age;
            lowInd = i;
        }
    }
    printf("Youngest Employee:\n");
    printf("ID: %d\n", employees[lowInd].id);
    printf("Age: %d\n", employees[lowInd].age);
    printf("Salary: %.2lf\n", employees[lowInd].salary);
}

int salaryInRange(struct Employee employees[], int n, double minSalary, double maxSalary) {
    int workers = 0;
    for(int i = 0; i<n; i++){
        if((employees[i].salary-minSalary>0.0001) && 0.0001<maxSalary-employees[i].salary) workers++;
    }
    return workers;
}

void salaryRaise(struct Employee employees[], int n, double increase) {
    for(int i=0;i<n;i++){
        employees[i].salary *= (1 + increase);
    }
}

/*
int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int n;
    
    printf("Enter the number of employees (up to %d): ", MAX_EMPLOYEES);
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX_EMPLOYEES) {
        printf("Invalid number of employees.\n");
        return 1;
    }
    
    inputEmployees(employees, n);
    displayEmployees(employees, n);
    
    double avgSal = averageSalary(employees, n);
    printf("Average Salary: %.2lf\n", avgSal);
    
    youngestEmployee(employees, n);
    
    double minSalary, maxSalary;
    printf("Enter the salary range:\n");
    printf("Minimum Salary: ");
    scanf("%lf", &minSalary);
    printf("Maximum Salary: ");
    scanf("%lf", &maxSalary);
    
    int count = salaryInRange(employees, n, minSalary, maxSalary);
    printf("Number of employees in the given salary range: %d\n", count);

    salaryRaise(employees, n, 0.05);
    printf("Salaries after 0.05 raise\n");
    displayEmployees(employees, n);
    
    return 0;
}
*/