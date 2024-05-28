#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);

int main() {
    int a, b;
    
    printf("Enter the first integer: ");
    scanf("%d", &a);
    printf("Enter the second integer: ");
    scanf("%d", &b);
    
    printf("Addition of %d and %d is: %d\n", a, b, add(a, b));
    printf("Subtraction of %d from %d is: %d\n", b, a, subtract(a, b));
    printf("Multiplication of %d and %d is: %d\n", a, b, multiply(a, b));
    
    if (b != 0) 
        printf("Division of %d by %d is: %.2f\n", a, b, divide(a, b));
    else 
        printf("Cannot divide by zero.\n");
    

    return 0;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero.\n");
        return 0;
    }
    return (float)a / b;
}
