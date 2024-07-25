#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // Function to find the index of the minimum element in a rotated sorted array
    int findMin(vector<int>& nums) {
        // If the array is not rotated, return the first index
        if(nums.front() < nums.back())
            return 0;

        int left = 0, right = nums.size() - 1;
        int minimum = 0;

        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] < nums[minimum])
                minimum = mid;

            if(nums[mid] < nums[right])
                right = mid - 1;
            else
                left = mid + 1;
        }

        return minimum;
    }

    // Function to search for a target element in a rotated sorted array
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = findMin(nums);
        int left = 0, right = n - 1;

        while(left <= right) {
            int mid = (left + right) / 2;

            if(nums[(mid + offset) % n] == target)
                return (mid + offset) % n;

            if(nums[(mid + offset) % n] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1; // Target not found
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = solution.search(nums, target);
    cout << "Index of target " << target << " is: " << result << endl;

    return 0;
}
