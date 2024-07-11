#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& v) {
        if (v.empty()) return "";

        std::string ans = "";
        std::sort(v.begin(), v.end());
        int n = v.size();
        std::string first = v[0], last = v[n-1];

        for (int i = 0; i < std::min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) {
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> strings;

    std::cout << "Enter number of strings: ";
    int numStrings;
    std::cin >> numStrings;

    std::cout << "Enter the strings:\n";
    for (int i = 0; i < numStrings; ++i) {
        std::string s;
        std::cin >> s;
        strings.push_back(s);
    }

    std::string result = sol.longestCommonPrefix(strings);

    std::cout << "The longest common prefix is: " << result << std::endl;

    return 0;
}
