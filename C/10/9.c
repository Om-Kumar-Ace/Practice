#include <stdio.h>

struct child {
    int x;
    char c;
};

struct parent {
    int x;
    struct child b;
};

int main() {
    
    struct parent var1 = {24, {190, 'A'}};

    printf("var1.x : %d\n", var1.x);           
    printf("var1.b.x : %d\n", var1.b.x);
    printf("var1.b.c : %c\n", var1.b.c);

    return 0;
}
