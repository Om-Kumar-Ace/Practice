#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nonZeroIndex = 0;
        
        // First pass: Move all non-zero elements to the front
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                nums[nonZeroIndex++] = nums[i];
            }
        }
        
        // Second pass: Fill the rest of the array with zeros
        for (int i = nonZeroIndex; i < n; ++i) {
            nums[i] = 0;
        }
    }
};
