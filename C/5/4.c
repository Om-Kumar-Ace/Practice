#include<stdio.h>

void main() {
    int arr[] = {10,11,8,10,9,14,11,14,3,8,10,7,8,6,7,5,6};
    int b[17] = {0}; 
    int a[17]; 
    int n = 0; 

    for (int i = 0; i < 17; i++) {
        int c = 0;
        int d = 0;
        for (int k = 0; k < n; k++) {
            if (arr[i] == a[k]) {
                d = 1;
                break;
            }
        }
        if (d) {

            for (int j = 0; j < 17; j++) {
                if (arr[i] == arr[j]) {
                    c++;

                }   
            }
            a[n] = arr[i];
            b[n] = c;
            n++;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d occurs %d times\n", a[i], b[i]);
    }

}