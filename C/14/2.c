#include <stdio.h>

void concatenate(char *destination, const char *source) {
    int i = 0;
    int j = 0;

    while (destination[i] != '\0') {
        i++;
    }

    while (source[j] != '\0') {
        destination[i] = source[j];
        i++;
        j++;
    }

    destination[i] = '\0';
}

int main() {
    char str1[100] = "Hello, "; 
    char str2[] = "World!";

    printf("Before concatenation: %s\n", str1);

    concatenate(str1, str2);

    printf("After concatenation: %s\n", str1);

    return 0;
}
