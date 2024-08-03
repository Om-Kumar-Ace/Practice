#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();  // Get the size of the input vector
        int curr = 0, mx = 0;  // Initialize variables to track the current count and maximum count of consecutive 1s

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                curr++;  // Increment current count if the element is 1
            } else {
                mx = max(curr, mx);  // Update maximum count if current count is greater
                curr = 0;  // Reset current count to 0 if the element is not 1
            }
        }

        return max(mx, curr);  // Return the maximum of mx and curr (in case the last element was 1)
    }
};

int main() {
    // Create an instance of the Solution class
    Solution sol;

    // Define test cases
    vector<int> test1 = {1, 1, 0, 1, 1, 1};  // Expected output: 3
    vector<int> test2 = {1, 0, 1, 1, 0, 1};  // Expected output: 2
    vector<int> test3 = {0, 0, 0, 0};        // Expected output: 0
    vector<int> test4 = {1, 1, 1, 1, 1};     // Expected output: 5

    // Test the function with the test cases
    cout << "Max consecutive 1s in test1: " << sol.findMaxConsecutiveOnes(test1) << endl;
    cout << "Max consecutive 1s in test2: " << sol.findMaxConsecutiveOnes(test2) << endl;
    cout << "Max consecutive 1s in test3: " << sol.findMaxConsecutiveOnes(test3) << endl;
    cout << "Max consecutive 1s in test4: " << sol.findMaxConsecutiveOnes(test4) << endl;

    return 0;
}
