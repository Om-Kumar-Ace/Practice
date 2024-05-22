#include <stdio.h>


typedef struct {
    int id;
    char name[100];
    float salary;
} Employee;

void main() {
    int n =2;
    Employee employees[n];

    for (int i = 0; i < n; i++) {
        printf("Enter data for employee %d:\n", i + 1);
        printf("Enter employee ID: ");
        scanf("%d", &employees[i].id);
        printf("Enter employee name: ");
        scanf(" %[^\n]", employees[i].name); 
        printf("Enter salary: ");
        scanf("%f", &employees[i].salary);
    }

 
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d ID: %d\n", i + 1, employees[i].id);
        printf("Employee Name: %s\n", employees[i].name);
        printf("Salary: %.2f\n", employees[i].salary);
    }


}