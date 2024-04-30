#include <stdio.h>

void main() {
    char arr[100];
    int freq[256] = {0};
    printf("Enter a string (without spaces): ");
    scanf("%s", arr);
    for (int i = 0; arr[i] != '\0'; i++) {
        freq[(int)arr[i]]++;
    }
    printf("Frequency of each character:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("'%c' occurs %d time(s)\n", (char)i, freq[i]);
        }
    }

}
