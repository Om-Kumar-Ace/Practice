#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int aCount = 0;
        int bCount = 0;
        int lesser = min(x, y);
        int result = 0;

        for (char c : s) {
            if (c > 'b') {
                result += min(aCount, bCount) * lesser;
                aCount = 0;
                bCount = 0;
            } else if (c == 'a') {
                if (x < y && bCount > 0) {
                    bCount--;
                    result += y;
                } else {
                    aCount++;
                }
            } else {
                if (x > y && aCount > 0) {
                    aCount--;
                    result += x;
                } else {
                    bCount++;
                }
            }
        }

        result += min(aCount, bCount) * lesser;
        return result;
    }
};

int main() {
    Solution sol;
    string s = "aabbaaxybbaabb";
    int x = 3;
    int y = 4;

    int result = sol.maximumGain(s, x, y);
    cout << "Maximum Gain: " << result << endl;

    return 0;
}
