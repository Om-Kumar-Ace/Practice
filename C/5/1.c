#include<stdio.h>

int main(){
    int arr[5],c=0;
    printf("Enter 5 no :- ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The 5 no are :- ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",arr[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        c=c+arr[i];
    }
    printf("/n The Sum of 5 no are:- %d",c);

    
    return 0;
}