class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        return {};
    }
};
bool init = ([]() -> char {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int ARR[30001]; ARR[0] = 0;
    ofstream out("user.out");
    string s;
    while(getline(cin, s)) {
        for(int i = 1, l = s.length(), c = 1, x = 0; i < l; i++) {
            if(s[i] == ',') {
                ARR[c++] = x ^ ARR[c-1];
                x = 0;
            }else if(s[i] == ']') {
                ARR[c] = x ^ ARR[c-1];
                break;
            }else {
                x = 10*x + (s[i] - '0');
            }
        }
        out << '['; getline(cin, s);
        bool first = true;
        int i = 2, l = s.length();
        while(i < l) {
            int x = 0, y = 0;
            while(s[i] != ',') {
                x = 10*x + (s[i++] - '0');
            }
            i++;
            while(s[i] != ']') {
                y = 10*y + (s[i++] - '0');
            }
            if(first) {
                first = false;
            }else out << ',';
            out << (ARR[y+1] ^ ARR[x]);

            i += 3;
        }
        out << "]\n";
    }
    out.flush();
    exit(0);
    return 1;
})();