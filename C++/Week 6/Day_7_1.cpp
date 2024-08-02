#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n + 1, -1);
        
        // Mark the presence of each number in nums by setting v[nums[i]] to nums[i]
        for (int i = 0; i < nums.size(); i++) {
            v[nums[i]] = nums[i];
        }
        
        // Find the missing number by checking for the -1 value in vector v
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == -1) return i;
        }
        
        return 0;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> nums = {3, 0, 1};
    int missing = solution.missingNumber(nums);
    // Expected output: 2
    return 0;
}
