class Solution {
public:
    int maxUniqueSplit(const string& s) {
        unordered_set<string> t; int n = s.length(), ans = 0;
        auto backtrack = [&](auto& backtrack, int i, int curr) {
            ans = max(ans, curr);
            if((curr + n-i) < ans) return;
            if(i >= n) return;
            string str = "";
            for(int j = i; j < n; j++) {
                str.push_back(s[j]);
                if(t.find(str) == t.end()) {
                    t.insert(str);
                    backtrack(backtrack, j + 1, curr + 1);
                    t.erase(str);
                }
            }
        };
        backtrack(backtrack, 0, 0);
        return ans;
    }
};