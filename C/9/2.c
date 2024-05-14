#include <stdio.h>

void main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[100] = {0};
    int temp[100] = {0};

    printf("Enter %d elements of the array: \n", size);
    for (int i = 0; i < size; i++) 
        scanf("%d", &arr[i]);
    
    for (int i = 0; i < size; i++) 
        temp[i] = arr[size - i - 1];

    printf("The reverse of the array is: ");
    for (int i = 0; i < size; i++) 
        printf("%d ", temp[i]);
    
    printf("\n");
}
