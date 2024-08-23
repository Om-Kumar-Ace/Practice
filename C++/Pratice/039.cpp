#include <bits/stdc++.h>
using namespace std;

void backtrack(int n, string current, vector<string> &result) {
    // Base case: if the current string length equals N, add it to the result
    if (current.length() == n) {
        result.push_back(current);
        return;
    }
    
    // Option 1: Add '0' to the current string and recurse
    backtrack(n, current + "0", result);
    
    // Option 2: Add '1' to the current string only if the last character isn't '1'
    if (current.empty() || current.back() != '1') {
        backtrack(n, current + "1", result);
    }
}

vector<string> generateString(int N) {
    vector<string> result;
    backtrack(N, "", result);
    return result;
}

int main() {
    // Example usage
    int N = 4;  // Length of the binary strings
    vector<string> binaryStrings = generateString(N);
    
    for (const string &str : binaryStrings) {
        cout << str << " ";
    }
    cout << endl;
    
    return 0;
}
