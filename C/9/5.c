#include <stdio.h>

int main() {
    int arr[100];
    int size, i, num, pos;

    printf("Enter size of array (max 100): ");
    scanf("%d", &size);

    if (size >= 100) 
        printf("Error: Size exceeds maximum limit.");
    

    printf("Enter elements of array:\n");
    for (i = 0; i < size; i++) 
        scanf("%d", &arr[i]);

    printf("Enter the number to insert: ");
    scanf("%d", &num);

    printf("Enter the position to insert (0 to %d): ", size);
    scanf("%d", &pos);

    if (pos < 0 || pos > size) 
        printf("Error: Invalid position.");
       
    
    for (i = size; i > pos; i--) 
        arr[i] = arr[i - 1];
    

    arr[pos] = num; 
    size++; 

    printf("Array after insertion at position %d:\n", pos);
    for (i = 0; i < size; i++) 
        printf("%d ", arr[i]);
    

}
