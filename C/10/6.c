#include <stdio.h>

int main()
{
    int a[10][10],b[10][10];
    int  n, flag = 0;

    printf("Enter no of rows :");
    scanf("%d", &n);

    printf("Enter elements : \n");
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            b[j][i]=a[i][j];
        }
    }
    printf("Orignal matrix : \n");
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < n ; j++)
        {
            printf(" %d",a[i][j]);
        } 
        printf("\n");      
    }
    printf("Transpose matrix : \n");
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < n ; j++)
        {
            printf(" %d",b[i][j]);
        } 
        printf("\n");      
    }
    
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j]-b[i][j]!=0)
            {
                flag=1;
                break;
            }
            
        }
        
    }
    if (flag>0)
    {
        printf("The matrix is Asymmetric");
    }
    else
    {
        printf("The matrix is Symmetric");
    }
    

    return 0;
}