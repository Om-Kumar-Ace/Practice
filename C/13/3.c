#include <stdio.h>

int main() {
    int sides = 6; 
    int target;
    float probability;

    printf("Enter the number you want to roll (1-6): ");
    scanf("%d", &target);

    if (target < 1 || target > 6) {
        printf("Invalid number. Please enter a number between 1 and 6.\n");
    } else {
        probability = 1.0 / sides;

        printf("The probability of rolling a %d on a six-sided die is %.2f\n", target, probability);
    }

    return 0;
}
