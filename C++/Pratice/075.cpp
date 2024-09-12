class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool occur[26] = {false}; 
        int count = 0;
        for(char ch : allowed) {
            occur[ch - 'a'] = true;
        }

        for(string& word : words) {
            if(check(word, occur)) {
                count++;
            }
        }
        return count;
    }

private:
    bool check(const string& str, const bool occur[]) {
        for(char ch : str) {
            if(!occur[ch - 'a']) {
                return false;
            }
        }
        return true;
    }
};

static const int kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

//om