#include<stdio.h>

void main(){
    int arr[]={5,7,6,2,4,11};
    int n=6;
    for (int i = 1; i < n; i++)
    {
        int temp=arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] <= temp)
                break;
            arr[j+1]=arr[j];
        }
        arr[j+1] = temp;
    }

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}