#include <stdio.h>
int ack(int m, int n)
{
    if (m == 0)
        return (n + 1);
    else if (m > 0 && n == 0)
        return (ack(m - 1, 1));
    else
        return (ack(m - 1, ack(m, n - 1)));
}
void main()
{
    int a, b, c;
    printf("\nEnter two numbers");
    scanf("%d%d", &a, &b);
    c = ack(a, b);
    printf("\nThe result is %d", c);
}