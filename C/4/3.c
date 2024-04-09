#include<stdio.h>

int main(){
    int n,r=0;
    printf("Enter the no. - ");
    scanf("%d",&n);
    int i=n/2;
    while (n>1)
    {
        if (n%i==0)
        {
            r++;
        }
        
        i--;
    }
    if (r!=0)
    {
        printf("not prime");
    }
    else
    {
        printf("Prime",r);
    }
    
    return 0;
}