#include <stdio.h>

int main() {
    char str[100];
    int vowelCount = 0, digitCount = 0;
    int i = 0;

    printf("Enter a string: ");
    scanf("%99[^\n]", str);

    while (str[i] != '\0') {
        char ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowelCount++;
        }
        
        if (ch >= '0' && ch <= '9') {
            digitCount++;
        }
        
        i++;
    }

    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of digits: %d\n", digitCount);

    return 0;
}
