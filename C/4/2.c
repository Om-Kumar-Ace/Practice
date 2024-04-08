#include<stdio.h>

int main(){
    float m;
    printf("Enter the marks");
    scanf("%f",&m);
    if (m>40)
    {
        printf("Pass");
    }
    else
    {
        printf("Fail");
    }
    
    return 0;
}