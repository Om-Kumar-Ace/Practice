#include <iostream>
#include <climits> // For INT_MAX and INT_MIN

class Solution {
public:
    int reverse(int x) {
        int rev = 0; // Initialize the variable to store the reversed number

        // Loop until x becomes 0
        while (x != 0) {
            // Check for potential overflow
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
                return 0; // Return 0 in case of overflow
            }

            // Append the last digit of x to rev
            rev = rev * 10 + x % 10;

            // Remove the last digit from x
            x /= 10;
        }

        return rev; // Return the reversed number
    }
};

int main() {
    Solution solution;
    int number;

    std::cout << "Enter an integer: ";
    std::cin >> number;

    int result = solution.reverse(number);

    std::cout << "Reversed number: " << result << std::endl;

    return 0;
}
