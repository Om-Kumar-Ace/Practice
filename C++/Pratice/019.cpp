#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string nextGreaterNumber(string s) {
    int n = s.size();
    if (n == 0) return "-1";
    
    // Step 1: Find the rightmost pivot where the sequence is decreasing
    int i = n - 2;
    while (i >= 0 && s[i] >= s[i + 1]) {
        --i;
    }

    // If no such pivot is found, no greater number can be formed
    if (i < 0) return "-1";

    // Step 2: Find the smallest digit greater than s[i] in the suffix
    int j = n - 1;
    while (s[j] <= s[i]) {
        --j;
    }

    // Step 3: Swap s[i] with s[j]
    swap(s[i], s[j]);

    // Step 4: Reverse the suffix starting at i + 1
    reverse(s.begin() + i + 1, s.end());

    return s;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << nextGreaterNumber(s) << endl;
    }
    return 0;
}
