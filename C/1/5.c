// Write a C program to perform addition, subtraction, division and multiplication of two numbers.

#include<stdio.h>

int main(){
    float a,b;
    printf("Enter the no. ");
    scanf("%f",&a );
    printf(" \n Enter the no. ");
    scanf("%f",&b);
    float sum ;
    sum = a+b;
    printf("The sum of two no %d", sum );
    float sub ;
    sub = a-b;
    printf("The sum of two no %d", sub );
    float multi ;
    multi = a*b;
    printf("The sum of two no %d", multi );
    float div ;
    div = a/b;
    printf("The sum of two no %d", div );

    return 0;
}