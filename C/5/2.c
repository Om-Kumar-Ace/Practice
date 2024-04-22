#include <stdio.h>
#include <ctype.h>

int main() {
    char input_char;

    printf("Enter a character: ");
    scanf(" %c", &input_char); // note the space before %c to consume any whitespace characters

    switch(input_char) {
        case 'A' ... 'Z':
            printf("Capital Letter\n");
            break;
        case 'a' ... 'z':
            printf("Small Letter\n");
            break;
        case '0' ... '9':
            printf("Digit\n");
            break;
        default:
            printf("Special Symbol\n");
            break;
    }

    return 0;
}
