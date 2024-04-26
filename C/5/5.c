#include<stdio.h>

int main(){
    float n,f=1;
    printf("Enetr the no :-");
    scanf("%f",&n);
    for (int i = n; i > 1; i--)
    {
        f=f*i;
    }
    printf("Factorial : %f ",f);
    
    return 0;
}