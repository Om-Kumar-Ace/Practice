#include <stdio.h>

int factorial(int n) {
    if (n < 0) 
        return 0; 
    int result = 1;
    for (int i = 1; i <= n; i++) 
        result *= i;

    return result;
}

void main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Factorial of %d is %d \n", number, factorial(number));
}
