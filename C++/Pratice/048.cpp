#include <iostream>

int CountSumConsecutiveNums(int n) {
    int count = 0;
    int k = 2;  // Start with at least 2 consecutive numbers

    while ((k * (k - 1)) / 2 < n) {
        // Calculate the sum of k consecutive numbers starting from x
        int numerator = n - (k * (k - 1)) / 2;
        if (numerator > 0 && numerator % k == 0) {
            count++;
        }
        k++;
    }

    return count;
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::cout << CountSumConsecutiveNums(N) << std::endl;
    }
    return 0;
}
