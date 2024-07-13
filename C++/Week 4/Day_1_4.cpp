#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > (i + 1) && nums[j] == nums[j - 1]) continue;
                
                int start = j + 1;
                int end = n - 1;

                while (start < end) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[start];
                    sum += nums[end];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});
                        int low = nums[start];
                        int high = nums[end];
                        start++, end--;
                        while (start < end && nums[start] == low) start++;
                        while (start < end && nums[end] == high) end--;
                    } else if (sum > target) {
                        end--;
                    } else {
                        start++;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    std::vector<std::vector<int>> result = solution.fourSum(nums, target);
    std::cout << "Quadruplets that sum to " << target << " are:" << std::endl;
    for (const auto& quadruplet : result) {
        std::cout << "[";
        for (int num : quadruplet) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
