#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    int minimumPushes(std::string word) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::vector<int> v(26, 0); // Initialize vector with zeros
        for (char& c : word)
            v[c - 'a']++;
        std::sort(v.begin(), v.end(), std::greater<int>());
        int a = 0;
        for (int i = 0; i < 26; ++i)
            a += v[i] * (i / 8 + 1);
        return a;
    }
};

int main() {
    Solution solution;
    std::string input = "example"; // Replace with the desired input word
    int result = solution.minimumPushes(input);
    std::cout << "Minimum pushes required: " << result << std::endl;
    return 0;
}
