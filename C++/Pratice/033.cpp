#include <bits/stdc++.h>
using namespace std;

vector<string> arrangeAuthors(vector<vector<string>> &s) {
    vector<string> result;
    for (int i = 0; i < s.size(); i++) {
        string author = to_string(i + 1) + ". " + s[i][0];
        result.push_back(author);
        char ch = 'A';
        for (int j = 1; j < s[i].size(); j++) {
            string book = "    " + string(1, ch) + ". " + s[i][j];
            result.push_back(book);
            ch++;
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> s(n);
        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;
            s[i].resize(m);
            for (int j = 0; j < m; j++) {
                cin >> s[i][j];
            }
        }
        vector<string> result = arrangeAuthors(s);
        for (string str : result) {
            cout << str << endl;
        }
    }
    return 0;
}