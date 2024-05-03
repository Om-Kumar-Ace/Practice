#include <stdio.h>

void main()
{
    int a[100], b[20] = {0}, n, z = 0, t = 0, p = 0;
    printf("Enter the number: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            a[p] = i;
            p++;
        }
    }

    for (int j = 0; j < p; j++)
    {
        printf("%d ", a[j]);
        int is_prime = 1;
        for (int k = 2; k < a[j] / 2; k++)
        {
            if (a[j] % k == 0)
            {
                is_prime = 0;
                break;
            }
        }

        if (is_prime && a[j] > 1)
        {
            b[t] = a[j];
            t++;
        }
    }

    printf("\n");

    for (int l = 0; l < t; l++)
    {
        if (b[l] > z)
        {
            z = b[l];
        }
        printf("%d ", b[l]);
    }

    printf("\nLargest prime factor: %d\n", z);
}