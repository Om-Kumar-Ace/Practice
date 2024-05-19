#include <stdio.h>
int main()
{
     int i = 0;
    int n;
    printf("ENTER A NUMBER (n) : ");
    scanf("%d", &n);
    
    do{
        printf("THE NUMBER IS %d \n", i+1);
        i++;
    } while (i < n);
    return 0;
}