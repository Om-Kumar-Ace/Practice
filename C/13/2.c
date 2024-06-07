#include<conio.h>
#include<stdio.h>

int fact(int);

void main()
{
    int f, r;
    printf("Enter any number: ");
    scanf("%d", &f);
    r = fact(f);
    printf("Factorial of %d is %d", f, r);
}

int fact(int f)
{
    if (f == 0)
        return 1;
    else
        return (f * fact(f - 1));
}
