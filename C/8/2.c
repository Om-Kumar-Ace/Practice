#include <stdio.h>
#include <string.h>

int main() {
    char st[] = "WXYZ";
    int len = strlen(st);
    int i, j;

    for (i = 0; i < len; i++) {
        for (j = 0; j < len - i - 1; j++) {
            printf(" ");
        }

        for (j = 0; j <= i; j++) {
            printf(" %c", st[j]);
        }

        printf("\n");
    }

    for (i = len - 2; i >= 0; i--) {
        for (j = 0; j < len - i - 1; j++) {
            printf(" ");
        }

        for (j = 0; j <= i; j++) {
            printf(" %c", st[j]);
        }

        printf("\n");
    }

    return 0;
}