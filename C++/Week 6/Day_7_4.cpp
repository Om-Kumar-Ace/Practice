#include <bits/stdc++.h> 
using namespace std;

int minimumRotations(int n, string s) {
    // Create a new string by concatenating s with itself
    string doubleS = s + s;

    // Iterate through the concatenated string
    for (int i = 1; i <= n; ++i) {
        // Check if the substring from index i of length n equals the original string
        if (doubleS.substr(i, n) == s) {
            return i; // Return the number of rotations
        }
    }

    // If no rotation matches, return n (though logically this should not happen for valid inputs)
    return n;
}

// Example usage
int main() {
    string s = "abcde";
    int n = s.length();
    int rotations = minimumRotations(n, s);
    cout << "Minimum rotations: " << rotations << endl; // Output: 5
    return 0;
}
