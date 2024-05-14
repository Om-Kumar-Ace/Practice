#include <stdio.h>

void main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[100]={0};

    printf("Enter %d elements of the array: \n", size);
    for (int i = 0; i < size; i++) 
        scanf("%d", &arr[i]);
    

    printf("The reverse of the array is: ");
    for (int i = size - 1; i >= 0; i--) 
        printf("%d ", arr[i]);
    
    printf("\n");

}