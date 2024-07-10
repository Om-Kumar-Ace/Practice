#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int len = 0;
        int x = s.length();

        for (int i = 0; i < x; i++) {
            // Check for odd length palindromes centered at i
            int l = i, r = i;
            while ((l >= 0 && r < x) && s[l] == s[r]) {
                if ((r - l + 1) > len) {
                    len = r - l + 1;
                    res = s.substr(l, len);
                }
                l--;
                r++;
            }

            // Check for even length palindromes centered between i and i+1
            l = i;
            r = i + 1;
            while ((l >= 0 && r < x) && s[l] == s[r]) {
                if ((r - l + 1) > len) {
                    len = r - l + 1;
                    res = s.substr(l, len);
                }
                l--;
                r++;
            }
        }

        return res;
    }
};

int main() {
    Solution solution;
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    string result = solution.longestPalindrome(input);

    cout << "Longest palindromic substring: " << result << endl;

    return 0;
}
