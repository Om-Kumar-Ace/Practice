#include <bits/stdc++.h>
using namespace std;

string minSubstring(string A, string B) {
    int m = A.size(), n = B.size();
    string res = A;
    for (int i = 0; i < m; i++) {
        int j = 0, k = i;
        while (j < n && k < m) {
            if (A[k] == B[j]) {
                j++;
            }
            k++;
        }
        if (j == n) {
            res = min(res, string(A.begin() + i, A.begin() + k), [](string a, string b) {
                return a.size() > b.size();
            });
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string A, B;
        cin >> A >> B;
        cout << minSubstring(A, B) << endl;
    }
    return 0;
}