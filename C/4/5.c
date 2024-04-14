#include<stdio.h>

int main(){
    printf("Enter the no.")
    scanf("%d",k);
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < (n-i)  ; k++)
        {
            printf("\t");
        }
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
    }
    return 0;
}