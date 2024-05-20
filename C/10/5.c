#include <stdio.h>

int main()
{
    float a[10][10], c, d = 1;
    int m, n, flag = 0;

    printf("Enter no of rows :");
    scanf("%d", &n);

    printf("Enter elements : \n");
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Orignal matrix : \n");

    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < n ; j++)
        {
            printf(" %f",a[i][j]);
        } 
        printf("\n");      
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i][i] == 0)
        {
            flag = 1;
            break;
        }
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                c = a[j][i] / a[i][i];
                for (int k = 0; k < n; k++)
                {
                    a[j][k] = a[j][k] - a[i][j] * c;
                }
            }
        }
    }
    if (flag != 0)
    {
        printf("The determinat of matrix is 0");
    }
    else
    {
        printf("The determinat of matrix is ");
        for (int i = 0; i < n; i++)
        {
            d = d * a[i][i];
        }
        printf("%f", d);
    }

    return 0;
}