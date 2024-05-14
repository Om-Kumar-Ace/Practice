#include <stdio.h>

void main() {
    char str[100];
    int count = 0;
    int i;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') 
            count++;    
    }
    printf("Number of spaces in the string: %d\n", count);

}