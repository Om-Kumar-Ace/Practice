#include <bits/stdc++.h> 
using namespace std;

bool checkMeta(string &str1, string &str2)
{
    // If the lengths are different, they cannot be meta strings
    if (str1.length() != str2.length()) {
        return false;
    }

    int count = 0;
    int first = -1, second = -1;

    // Iterate through the strings to find differing positions
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) {
            count++;
            if (count > 2) return false;  // More than 2 differences, not meta strings

            if (first == -1) {
                first = i;
            } else {
                second = i;
            }
        }
    }

    // Check if exactly two characters differ and they can be swapped to make the strings equal
    return (count == 2 && str1[first] == str2[second] && str1[second] == str2[first]);
}
int main() {
    string str1 = "Coding";
    string str2 = "Codnig";

    if (checkMeta(str1, str2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
