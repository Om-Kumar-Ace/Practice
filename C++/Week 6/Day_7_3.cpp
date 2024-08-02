#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    static int minSwaps(vector<int>& nums) {
        const int n = nums.size();
        const int n1 = count(nums.begin(), nums.end(), 1);
        int mswap = INT_MAX, cnt1 = 0;

        for (int l = 0, r = 0; r < n + n1; r++) {
            cnt1 += nums[r % n]; // Count 1s in the current window
            if (r - l + 1 > n1)  // If the window size exceeds the count of 1s
                cnt1 -= nums[l++ % n]; // Slide the window
            if (r - l + 1 == n1) // When window size matches the count of 1s
                mswap = min(mswap, n1 - cnt1); // Calculate min swaps
        }
        return mswap;
    }
};

// Initialization to speed up input/output
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
