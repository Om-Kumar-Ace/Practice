#include<stdio.h>

void main(){
    int a[100], n, p=0;
    printf("Enter the number: ");
    scanf("%d", &n);
    
   
    for (int i = 1; i <= n;  i++) {
        if (n%i == 0) {
            a[p] = i;
            p++;
            // printf("%d ", i);
        }
    }
    
    for (int j = 0; j < p; j++) {
        printf("%d ", a[j]);
    }
    printf("\n");
}