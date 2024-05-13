#include<stdio.h>

int main(){
    int x ,y,z,n;
    printf("Enter 3 digit no.");
    scanf("%d",&n);
    x=n%10;
    y=(n/10)%10;
    z=n/100;
    if (y==x+z)
    {
        printf("Middle digit is equal to sum of others in %d",n);
    }
    else
    {
        printf("Middle digit is not equal to sum of others in %d",n);
        
    }
    
    return 0;
}