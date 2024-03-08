// Write a C program to perform addition, subtraction, division and multiplication of two numbers.

#include<stdio.h>

int main(){
    float a,b;
    printf(" Enter the no. ");
    scanf("%f",&a );
    printf("\n Enter the no. ");
    scanf("%f",&b);
    
    float sum ;
    sum = a + b;
    printf("\n The sum of two no %f", sum );

    float sub ;
    sub = a - b;
    printf("\n The sub of two no %f", sub );

    float multi ;
    multi = a * b;
    printf("\n The multi of two no %f", multi );

    float div ;
    div = a / b;
    printf("\n The div of two no %d", div );

    return 0;
}