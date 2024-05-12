#include<stdio.h>

int reverse(int num) {
    int reversed = 0;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}

int main(){
    for (int i = 0; i < 100; i++) {
        int x = i;
        int y = i * i;
        int z = reverse(x);
        if (y == z * z) {
            printf("%d=%d : %d=%d\n", x, y, z, z * z);
        }
    }
    
    return 0;
}
