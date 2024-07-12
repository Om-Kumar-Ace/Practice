#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> opened;
        unordered_map<int, int> pair;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                opened.push(i);
            } else if (s[i] == ')') {
                int j = opened.top();
                opened.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        string result;
        int i = 0;
        int direction = 1; 

        while (i < n) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                direction = -direction;
            } else {
                result.push_back(s[i]);
            }
            i += direction;
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "(u(love)i)";
    
    string result = sol.reverseParentheses(s);
    cout << "Reversed Parentheses String: " << result << endl;

    return 0;
}
