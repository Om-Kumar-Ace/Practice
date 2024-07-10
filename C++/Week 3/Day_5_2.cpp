#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm> // For std::max

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.length();
        int maxLength = 0;
        std::unordered_set<char> charSet;
        int prev = 0;

        for(int i = 0; i < n; i++) {
            // Check if the character is already in the set
            while(charSet.count(s[i])) {
                charSet.erase(s[prev]);
                prev++;
            }
            charSet.insert(s[i]);
            maxLength = std::max(maxLength, i - prev + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    std::string input;

    std::cout << "Enter a string: ";
    std::cin >> input;

    int result = solution.lengthOfLongestSubstring(input);

    std::cout << "Length of the longest substring without repeating characters: " << result << std::endl;

    return 0;
}
