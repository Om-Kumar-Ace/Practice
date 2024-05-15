#include <stdio.h>

void main() {
    int arr[100];
    int size, i, num;

    printf("Enter size of array (max 100): ");
    scanf("%d", &size);

    if (size >= 100) 
        printf("Error: Size exceeds maximum limit.");

    printf("Enter elements of array:\n");
    for (i = 0; i < size; i++) 
        scanf("%d", &arr[i]);

    printf("Enter the number to insert at the end: ");
    scanf("%d", &num);

    arr[size] = num; 

    size++; 

    printf("Array after insertion at the end:\n");
    for (i = 0; i < size; i++) 
        printf("%d ", arr[i]);
    

}