#include<stdio.h>

int main(){
    int n,m=0;
    printf("Enter no of rows :");
    scanf("%d",&n);
    n++;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j >=i ; j--)
            printf("  ");
        for (int j = 1; j <=i ; j++)
            printf(" %d",j);
        for (int j = i-1; j > 0 ; j--)
            printf(" %d",j);
        printf("\n");
    }
        printf("\n");
        printf("***********************************************************\n");
        printf("\n");
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <=i ; j++)
            printf(" %d",j);
        for (int k = 1; k <=n-i ; k++)
            printf("    ");
        for (int j = i; j > 0 ; j--)
            printf(" %d",j);
        printf("\n");
        m+2;
    }
    return 0;
}