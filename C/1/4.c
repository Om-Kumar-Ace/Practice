// Write a C program to calculate area and circumference of a circle. 
#include<stdio.h>

int main(){
    float  r=7 , pi=3.14 ;
    float area , circum;
    area = pi*r*r;
    circum = 2*pi*r;
    printf("The area of circle is %d \n",area);
    printf("The circumference of circle is %d \n ",circum);
    return 0;
}