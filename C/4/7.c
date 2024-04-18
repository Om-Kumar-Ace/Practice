#include <stdio.h>

int main()
{
    int n, f;
    printf("Enter the no of rows :-");
    scanf("%d", &n);
    printf("For Hollow press 1 :-");
    scanf("%d", &f);
    if (f != 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (n - i); j++)
            {
                printf(" ");
            }
            for (int k = 0; k < i; k++)
            {
                printf(" *");
            }
            printf("\n");
        }
        for (int l = 0; l < n; l++)
        {
            for (int h = 0; h < l; h++)
            {
                printf(" ");
            }
            for (int g = 0; g < (n - l); g++)
            {
                printf(" *");
            }
            printf("\n");
        }
    }
    else
    {
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (n - i); j++)
            {
                printf(" ");
            }
            for (int k = 0; k < i; k++)
            {
                if (k==0||k==(i-1))
                {
                    printf(" *");
                }
                else
                {
                    printf("  ");
                }
                
            }
            printf("\n");
        }
        for (int l = 0; l < n; l++)
        {
            for (int h = 0; h < l; h++)
            {
                printf(" ");
            }
            for (int g = 0; g < (n - l); g++)
            {   
                if (g==0||g==((n-l)-1))
                {
                printf(" *");
                }
                else
                {
                    printf("  ");
                }
                
            }
            printf("\n");
        }
    }
    
    return 0;
}