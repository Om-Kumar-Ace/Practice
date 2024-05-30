#include<stdio.h>

void fib(int m){
    int a,b=0,c=2,d=1;
    printf("%5d%5d",b,d);
    while (c<m )
    {
        a=b+d;
        printf("%5d",a);
        b=d;
        d=a;
        c++; 
    }    
}

int main(){
    int n;
    printf("Enter the no :");
    scanf("%d",&n);
    printf("The fibocanni sequence is :");
    fib(n);
    return 0;
}