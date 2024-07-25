#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int ans1 = -1;
        int ans2 = -1;

        int i = 0;
        int j = n - 1;

        // Find the first occurrence of the target
        while (i <= j) {
            int mid = (i + j) / 2;

            if (nums[mid] == target) {
                ans1 = mid;
                j = mid - 1; // Search in the left half
            } else if (nums[mid] > target) {
                j = mid - 1; // Move left
            } else {
                i = mid + 1; // Move right
            }
        }

        i = 0;
        j = n - 1;

        // Find the last occurrence of the target
        while (i <= j) {
            int mid = (i + j) / 2;

            if (nums[mid] == target) {
                ans2 = mid;
                i = mid + 1; // Search in the right half
            } else if (nums[mid] > target) {
                j = mid - 1; // Move left
            } else {
                i = mid + 1; // Move right
            }
        }

        return {ans1, ans2};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = solution.searchRange(nums, target);

    cout << "Start: " << result[0] << ", End: " << result[1] << endl;

    return 0;
}
