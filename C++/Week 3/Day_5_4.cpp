#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1 || numRows >= n) {
            return s;
        }

        string ans = "";
        int cycleLen = 2 * numRows - 2;

        // Loop through each row
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ans += s[j + i];  // Add character from the current column
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                    ans += s[j + cycleLen - i];  // Add character from the diagonal
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string input;
    int numRows;

    cout << "Enter a string: ";
    getline(cin, input);
    cout << "Enter number of rows: ";
    cin >> numRows;

    string result = solution.convert(input, numRows);

    cout << "Converted string in zigzag pattern: " << result << endl;

    return 0;
}
