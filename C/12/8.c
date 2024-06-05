#include <stdio.h>
void main()
{
    int a[4][3], i, j, k, row, col;
    puts("Enter the elemennts");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    }
    puts("Enter the number:");
    scanf("%d", &k);
    puts("Enter row and column:");
    scanf("%d %d", &row, &col);
    row--;
    col--;

    for (i = 2; i >= 0; i--)
    {
        for (j = 2; j >= 0; j--)
        {
            a[i + 1][j + 1] = a[i][j];
            if (i == row && j == col - 1)
                break;
        }
    }
    a[row][col] = k;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}