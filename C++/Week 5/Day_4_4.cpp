#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> brackets(n+2, INT_MIN);
        brackets[0] = -1;
        int track = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                track++;
            } else {
                track--;
                if (track < 0) {
                    track = 0;
                    brackets[0] = i;
                }
            }
            if (brackets[track] == INT_MIN) {
                brackets[track] = i;
            } else {
                ans = max(ans, i - brackets[track]);
            }
            brackets[track+1] = INT_MIN;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s;

    // Test case
    s = "(()))())(";
    cout << "The length of the longest valid parentheses substring is: " << sol.longestValidParentheses(s) << endl;

    // Additional test cases
    s = "(()";
    cout << "The length of the longest valid parentheses substring is: " << sol.longestValidParentheses(s) << endl;

    s = ")()())";
    cout << "The length of the longest valid parentheses substring is: " << sol.longestValidParentheses(s) << endl;

    s = "";
    cout << "The length of the longest valid parentheses substring is: " << sol.longestValidParentheses(s) << endl;

    return 0;
}
