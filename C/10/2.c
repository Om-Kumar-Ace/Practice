#include<stdio.h>

int main(){
    int n;
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
    return 0;
}