#include <stdio.h>

void main() {
    int arr[10] = {0};
    int n = 10; 

    printf("Enter array of 10 no. : \n");
    for (int i = 0; i < n; i++) 
        scanf("%d ", &arr[i]);
    
    printf("Original array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    
    printf("\n");

}