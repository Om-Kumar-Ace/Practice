#include<stdio.h>
double factorial (double n) ;

int main(){
    double sum= 0,fact,start=4,n;
    int track =0;
    printf("Enter the value of n :");
    scanf("%lf",&n);
    fact=factorial(start);
    printf("****%lf\n",fact);
    sum =sum +1/fact;
    while (start<=n )
    {
        start=start+2;
        if (track==0)
        {
            fact=factorial(start);
            printf("****%lf\n",fact);
            sum =sum -1/fact;
            track=track+1;
        }
        else if (track==1)
        {
            fact=factorial(start);
            printf("****%lf\n",fact);
            sum =sum +1/fact;
            track=track-1;
        }
        
    }
    printf("Final sum = %f",sum);
    return 0;
}

double factorial (double n)
{
    if (n==1)
        return 1;
    else
        return n*factorial(n-1);
}