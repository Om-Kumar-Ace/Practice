#include <stdio.h>
#include <string.h>

void intToRoman(int num, char *roman) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int i = 0;
    while (num > 0) {
        while (num >= values[i]) {
            num -= values[i];
            strcat(roman, symbols[i]);
        }
        i++;
    }
}

int main() {
    int num;
    char roman[20] = "";  

    printf("Enter a number: ");
    scanf("%d", &num);

    intToRoman(num, roman);
    printf("Roman numeral: %s\n", roman);

    return 0;
}
