#include<stdio.h>

int main(){
    int a,b,c,d;
    printf("Enter Vaule");
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        scanf("%d",&d);
    int h = (a>b)?(a>c)?(a>b)?a:d:(c>d)?c:d:(b>c)?(b>d)?b:d:(c>d)?c:d ;
    printf("\n Max No. %d",h);
    return 0;
}