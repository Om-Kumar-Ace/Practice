#include<stdio.h>

int main(){
    int y;
    printf("Please Enter the no-");
    scanf("%d",&y);
    if (y%100==0)
    {
        if (y%400==0)
        {
            printf("The year is leap year");
        }
        else
        {
            printf("The year is not a leap year");
        }
    }
    else if (y%4==0)
    {
        printf("The year is leap year");
    }
    else
    {
        printf("The year is not leap year");
    }
    
    

    return 0;
}