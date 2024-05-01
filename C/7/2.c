#include<stdio.h>

int main(){
    int r=5;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (i==j)
            {
                printf(" *");
            }
            else
            {
                printf(" .");
            }
            
            
        }
    printf("\n");
    }
    
    return 0;
}