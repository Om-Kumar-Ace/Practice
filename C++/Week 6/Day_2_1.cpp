#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
        
            if (nums[mid] == target) {
                return mid;
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int result = solution.searchInsert(nums, target);
    std::cout << "Insert position for target " << target << " is: " << result << std::endl;

    target = 2;
    result = solution.searchInsert(nums, target);
    std::cout << "Insert position for target " << target << " is: " << result << std::endl;

    target = 7;
    result = solution.searchInsert(nums, target);
    std::cout << "Insert position for target " << target << " is: " << result << std::endl;

    target = 0;
    result = solution.searchInsert(nums, target);
    std::cout << "Insert position for target " << target << " is: " << result << std::endl;

    return 0;
}
