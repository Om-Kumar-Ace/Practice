#include<stdio.h>

int main(){
    int a[40],b[12]={0};
    int x,y,z;
    printf("Enter the no. (range 0-11) :-");
    for (int i = 0; i < 40; i++)
    {
        scanf("%d",&a[i]);
        for (int j = 0; j < 12; j++)
        {
            if (a[i]==j)
            {
                b[j]++;
            }
            
        }
        if (a[i]>11)
        {
            break;
        }
        
    }
    for (int k = 0; k < 12; k++)
    {
        printf("%d appers %d times \n",k,b[k]);
    }
    
    
    return 0;
}