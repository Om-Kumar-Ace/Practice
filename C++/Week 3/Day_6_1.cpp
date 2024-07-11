#include <iostream>
#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0, sign = 1;
        int result = 0;

        // Discard leading whitespaces
        while (i < s.size() && s[i] == ' ') i++;

        // Check for sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert characters to integer
        while (i < s.size() && std::isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow and underflow
            if (result > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    std::string test1 = "42";
    std::string test2 = "   -42";
    std::string test3 = "4193 with words";
    std::string test4 = "words and 987";
    std::string test5 = "-91283472332";

    std::cout << "Result of myAtoi(\"" << test1 << "\"): " << solution.myAtoi(test1) << std::endl;
    std::cout << "Result of myAtoi(\"" << test2 << "\"): " << solution.myAtoi(test2) << std::endl;
    std::cout << "Result of myAtoi(\"" << test3 << "\"): " << solution.myAtoi(test3) << std::endl;
    std::cout << "Result of myAtoi(\"" << test4 << "\"): " << solution.myAtoi(test4) << std::endl;
    std::cout << "Result of myAtoi(\"" << test5 << "\"): " << solution.myAtoi(test5) << std::endl;

    return 0;
}
