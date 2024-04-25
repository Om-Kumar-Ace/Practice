#include<stdio.h>

int main(){
    float n,f=1;
    printf("Enetr the no :-");
    scanf("%f",&n);
    for (int i = 0; i < n; i++)
    {
        f=f*i;
    }
    printf("Factorial : %f ",f);
    
    return 0;
}