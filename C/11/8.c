#include <stdio.h>

int sumOfNaturalNumbers(int n);

int main() {
    int n = 20;
    int sum = sumOfNaturalNumbers(n);

    printf("The sum of the first %d natural numbers is: %d\n", n, sum);

    return 0;
}

int sumOfNaturalNumbers(int n) {
    if (n == 1) {
        return 1; 
    } else {
        return n + sumOfNaturalNumbers(n - 1); 
    }
}