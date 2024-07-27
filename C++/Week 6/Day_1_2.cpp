#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> ans(nums.begin(), nums.end());
        sort(ans.begin(), ans.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums == ans) {
                return true;
            }
            rotate(nums.begin(), nums.begin() + 1, nums.end());
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 4, 5, 1, 2};

    bool result = solution.check(nums);
    cout << "Can the array be sorted by rotating it? " << (result ? "Yes" : "No") << endl;

    return 0;
}
