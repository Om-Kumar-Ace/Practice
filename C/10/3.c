#include <stdio.h>

void main() {
    int arr[100] = {0};
    int size, i, target;

    printf("Enter size of array (max 100): ");
    scanf("%d", &size);
    printf("Enter elements of array:\n");
    for (i = 0; i < size; i++) 
        scanf("%d", &arr[i]);
    
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    for(i = 0; i < size ; i++) {
        if(arr[i] == target) {
            printf("Element found at positon %d\n", i+1);
            break;
        }
    }

    if(i==size) 
        printf("Element not found in the array\n");
    
}