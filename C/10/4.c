#include<stdio.h>

int main(){
    int a[10][10],b[10][10],m,n;
    printf("Enter no of rows :");
    scanf("%d",&m);
    printf("Enter no of columns :");
    scanf("%d",&n);

    printf("Enter elements : \n");
    for (int i = 0; i < m ; i++)
    {
        for (int j = 0; j < n ; j++)
        {
            scanf("%d",&a[i][j]);
            b[j][i]=a[i][j];
        }       
    }

    printf("Orignal matrix : \n");
    for (int i = 0; i < m ; i++)
    {
        for (int j = 0; j < n ; j++)
        {
            printf(" %d",a[i][j]);
        } 
        printf("\n");      
    }

    printf("Transpose matrix : \n");
    for (int i = 0; i < m ; i++)
    {
        for (int j = 0; j < n ; j++)
        {
            printf(" %d",b[i][j]);
        } 
        printf("\n");      
    }
    
    return 0;
}