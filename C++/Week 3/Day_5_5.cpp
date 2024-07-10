#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> map{
            {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
            {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
            {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"},
            {1000, "M"}
        };

        string s = "";
        int l = map.size() - 1;

        while (num != 0) {
            while (map[l].first > num) {
                l--;
            }
            s += map[l].second;
            num -= map[l].first;
        }

        return s;
    }
};

int main() {
    Solution solution;
    int input;

    cout << "Enter an integer: ";
    cin >> input;

    string result = solution.intToRoman(input);

    cout << "Roman numeral: " << result << endl;

    return 0;
}
