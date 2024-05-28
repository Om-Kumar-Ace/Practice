#include <stdio.h>

void swapByValue(int a, int b);
void swapByReference(int *a, int *b);

int main() {
    int x, y;

    printf("Enter the first integer: ");
    scanf("%d", &x);
    printf("Enter the second integer: ");
    scanf("%d", &y);

    printf("\nBefore swapping: x = %d, y = %d\n", x, y);
    swapByValue(x, y);
    printf("After swapping (by value): x = %d, y = %d\n", x, y);

    swapByReference(&x, &y);
    printf("After swapping (by reference): x = %d, y = %d\n", x, y);

    return 0;
}

void swapByValue(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("Inside swapByValue function: a = %d, b = %d\n", a, b);
}

void swapByReference(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
