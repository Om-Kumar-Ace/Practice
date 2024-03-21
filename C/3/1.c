#include<stdio.h>

int main(){
    int a ,b;
    printf("Enter value of a & b ");
    scanf("%d",&a);
    scanf("%d",&b);
    int c = (a>b) ? a :b;
    printf("%d ",c);
    return 0;
}