#include<stdio.h>

int main(){
    int i ,j;
    printf("The triplets are given :\n");
    for (int i = 1; i < 100; i+=2)
    {
        for (int j = 0; j < 5000; j++)
        {
            if ((i*i)+(j*j)==(j+1)*(j+1))
                printf("%d %d %d\n",i,j,j+1);
        }   
    }
    return 0;
}