#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void recursiveSelectionSort(int arr[], int n, int index)
{
    if (index == n)
        return;

    int minIndex = index;
    for (int j = index + 1; j < n; j++)
    {
        if (arr[j] < arr[minIndex])
            minIndex = j;
    }

    swap(&arr[minIndex], &arr[index]);

    recursiveSelectionSort(arr, n, index + 1);
}

int main()
{
    int arr[100] = {0};
    int n;

    printf("Enter size of array (max 100): ");
    scanf("%d", &n);
    printf("Enter elements of array:\n");
    for (int j = 0; j < n; j++)
        scanf("%d", &arr[j]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    recursiveSelectionSort(arr, n, 0);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
