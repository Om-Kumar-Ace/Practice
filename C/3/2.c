#include<stdio.h>

int main(){
    int  a,b,c,d,e,f,s,o,p=0;
    
    printf("Please Enter Over ");
        scanf("%d",&o);

    printf("Please Enter value in 0 1 2 3 4 6 ");
    for ( o; o < 2; o++)
    {
        printf("\n Enter run ");
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        scanf("%d",&d);
        scanf("%d",&e);
        scanf("%d",&f);
        s=p+a+b+c+d+e+f;

    float runrate;
    runrate=s/o;
    printf("The Runrate is %f",runrate);
    s=p;}
    return 0;
}