#include<stdio.h>

int main(){
    int n;
    printf("Enter the no of rows-");
    scanf("%d",&n);
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j <(n - i); j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf(" *");
        }
        printf("\n");
        
    }
    for (int l = 0; l < n ; l++)
    {
        for (int h = 0; h < l; h++)
        {
            printf(" ");
        }
        for (int g = 0; g < (n-l); g++)
        {
            printf(" *");
        }
        printf("\n");
        
    }
    
    return 0;
}