#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class Solution {
    std::unordered_map<char, std::string> m;
    
    std::vector<std::string> output;

    void dfs(const std::string& digits, int index, std::string& s) {
        if (index == digits.size()) {
            output.push_back(s);
            return;
        }

        for (char i : m[digits[index]]) {
            s.push_back(i);            
            dfs(digits, index + 1, s);  
            s.pop_back();            
        }
    }

public:
    Solution() : m{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}} {}

    std::vector<std::string> letterCombinations(std::string digits) {
        std::string s;
        if (!digits.empty()) dfs(digits, 0, s);
        return output;
    }
};

int main() {
    Solution solution;
    std::string digits = "23";

    std::vector<std::string> result = solution.letterCombinations(digits);
    std::cout << "Letter combinations for " << digits << " are: ";
    for (const std::string& combination : result) {
        std::cout << combination << " ";
    }
    std::cout << std::endl;

    return 0;
}
