#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakpoint = -1;

        // Find the breakpoint where nums[i] < nums[i + 1]
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                breakpoint = i;
                break;
            }
        }

        // If no breakpoint is found, the permutation is the last permutation
        if (breakpoint == -1) {
            sort(nums.begin(), nums.end());
            return;
        }

        // Find the element just larger than nums[breakpoint]
        for (int i = n - 1; i > breakpoint; --i) {
            if (nums[i] > nums[breakpoint]) {
                swap(nums[i], nums[breakpoint]);
                break;
            }
        }

        // Reverse the order after the breakpoint
        reverse(nums.begin() + breakpoint + 1, nums.end());
    }
};

int main() {
    vector<int> nums = {1, 2, 3};

    Solution sol;
    sol.nextPermutation(nums);

    // Print the result
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
