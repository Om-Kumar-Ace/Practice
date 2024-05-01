#include <stdio.h>

int main()
{
    int rows;
    int i, j;
    printf("Enter a no :-");
    scanf("%d",&rows);
    for (i = 0; i < rows; i++)
    {
        char ch = 'A';

        for (j = 0; j <= i; j++)
        {

            printf("%c", ch);

            ch++;
        }
        printf("\n");
    }

    return 0;
}