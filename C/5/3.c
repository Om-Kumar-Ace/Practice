#include<stdio.h>

int main(){
    int n,c=1;
    printf("Enter the no. of rows :-");
    scanf("%d",&n);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d ",c);
            c++;
        }
        printf("\n");
        
    }
    
    return 0;
}