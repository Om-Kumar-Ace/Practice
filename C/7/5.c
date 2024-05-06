#include <stdio.h>

int main() {
    int r = 5, c = 26;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == j % 8 || i + j % 8 == 8) {
                printf("%c", 'a' + j);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}