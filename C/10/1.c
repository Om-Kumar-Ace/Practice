#include <stdio.h>

void main() {
    int arr[100] = {0};
    int size, i, num, pos;

    printf("Enter size of array (max 100): ");
    scanf("%d", &size);

    printf("Enter elements of array:\n");
    for (i = 0; i < size; i++) 
        scanf("%d", &arr[i]);

    for (i = 0; i < size - 1; i++) {
        pos = i;
        for (int k = i + 1; k < size; k++) {
            if (arr[k] < arr[pos])           
                pos = k;     
        }
        if (pos != i) {
            num = arr[i];
            arr[i] = arr[pos];
            arr[pos] = num;
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < size; i++) 
        printf("%d ", arr[i]);
    
}
