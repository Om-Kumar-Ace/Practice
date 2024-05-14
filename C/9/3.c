#include<stdio.h>

void main(){
    int arr[100]={0};
    int size, i, num;

    printf("Enter size of array (max 100): ");
    scanf("%d", &size);

    if (size >=100) {
        printf("Error: Size exceeds maximum limit.");
        return 1;
    }

    printf("Enter elements of array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to insert: ");
    scanf("%d", &num);


    for (i = size - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }

    arr[0] = num; 

    size++; 

    printf("Array after insertion:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

}