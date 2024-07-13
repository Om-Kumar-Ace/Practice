#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int ans = 1e6;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) return target;
                else if (sum > target) k--;
                else j++;

                if (std::abs(sum - target) < std::abs(ans - target)) ans = sum;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    int result = solution.threeSumClosest(nums, target);
    std::cout << "The sum that is closest to the target is: " << result << std::endl;

    return 0;
}
