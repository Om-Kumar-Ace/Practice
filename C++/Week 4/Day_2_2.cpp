#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;

        for(int i = 0; i < n; i++) {
            char ch = s[i];
            
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if(st.empty()) {
                    return false;
                }
                
                if((ch == ')' && st.top() == '(') ||
                   (ch == '}' && st.top() == '{') ||
                   (ch == ']' && st.top() == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        
        return st.empty();
    }
};

// Test code
int main() {
    Solution solution;
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";
    string s4 = "([)]";
    string s5 = "{[]}";

    cout << solution.isValid(s1) << endl; // Expected output: 1 (true)
    cout << solution.isValid(s2) << endl; // Expected output: 1 (true)
    cout << solution.isValid(s3) << endl; // Expected output: 0 (false)
    cout << solution.isValid(s4) << endl; // Expected output: 0 (false)
    cout << solution.isValid(s5) << endl; // Expected output: 1 (true)

    return 0;
}
