#include <string>
using namespace std;

class Solution {
private:
    void solve(string& ans) {
        string x;
        int count = 1;
        char a;

        // Iterate over the string to count consecutive characters
        for (int i = 0; i < ans.size() - 1; i++) {
            a = ans[i];
            if (ans[i] == ans[i + 1]) {
                count++;
            } else {
                // Append count and character to the result string
                x += char(count + '0'); 
                x += ans[i];
                count = 1;
            }
        }

        // Append the last group of characters
        x += char(count + '0');
        x += ans[ans.size() - 1];
        
        // Update the original string
        ans = x;
    }

public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string ans = "1"; // Start with the first term of the sequence
        
        for (int i = 1; i < n; i++) {
            solve(ans);
        }
        return ans;
    }
};
