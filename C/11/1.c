#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("There are no prime numbers less than or equal to %d.\n", n);
        return 0;
    }

    int highest_prime = -1;

    for (int num = 2; num <= n; num++) {
        int is_prime = 1; 

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime) {
            highest_prime = num;
        }
    }

    if (highest_prime != -1) {
        printf("The highest prime factorial of %d is %d.\n", n, highest_prime);
    } else {
        printf("There are no prime numbers less than or equal to %d.\n", n);
    }

    return 0;
}
