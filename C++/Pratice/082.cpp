class Solution {
private:
    static const int VOWEL_MASK[128];

public:
    int findTheLongestSubstring(string s) {
        vector<int> firstOccurrence(32, -2);
        firstOccurrence[0] = -1;
        int mask = 0;
        int maxLength = 0;
        
        for (int i = 0; i < s.length(); i++) {
            mask ^= VOWEL_MASK[s[i]];
            if (firstOccurrence[mask] == -2) {
                firstOccurrence[mask] = i;
            } else {
                maxLength = max(maxLength, i - firstOccurrence[mask]);
            }
        }
        
        return maxLength;
    }
};

const int Solution::VOWEL_MASK[128] = {
    ['a'] = 1, ['e'] = 2, ['i'] = 4, ['o'] = 8, ['u'] = 16
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
//om