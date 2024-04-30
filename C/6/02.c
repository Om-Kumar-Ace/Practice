#include<stdio.h>

int main(){
    int n;
    printf("Enter the no :-");
    printf("%d",&n);
    switch (n % 2) {
        case 0:
            printf("%d is even.\n", n);
            break;
        case 1:
            printf("%d is odd.\n", n);
            break;
        default:
            printf("Invalid input.\n");
    }
    return 0;
}