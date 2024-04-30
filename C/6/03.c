#include <stdio.h>
void main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[100] = {0};
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    printf("Sum of the array elements: %d\n", sum);
}