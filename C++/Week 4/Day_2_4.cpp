#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void solve(int total, int open, int close, string s, vector<string>& ans) {
        // Base case: if the current string length is equal to total, add it to the result
        if (s.size() == total) {
            ans.push_back(s);
            return;
        }

        // If the number of open parentheses is greater than close, we can add a close parenthesis
        if (open > close) {
            solve(total, open, close + 1, s + ')', ans);
        }

        // If the number of open parentheses is less than half of the total, we can add an open parenthesis
        if (open < total / 2) {
            solve(total, open + 1, close, s + '(', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        int tot = 2 * n;  // Total number of parentheses in the result
        vector<string> ans;

        solve(tot, 0, 0, "", ans);  // Start the recursive generation

        return ans;
    }
};

// Test code
int main() {
    Solution solution;
    int n = 3;  // Example input
    vector<string> result = solution.generateParenthesis(n);

    // Print the generated combinations
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}
