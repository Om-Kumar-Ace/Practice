#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Example test cases
    vector<int> test1 = {2, 2, 1};
    vector<int> test2 = {4, 1, 2, 1, 2};
    vector<int> test3 = {1};

    cout << "Test Case 1: " << solution.singleNumber(test1) << endl; // Output: 1
    cout << "Test Case 2: " << solution.singleNumber(test2) << endl; // Output: 4
    cout << "Test Case 3: " << solution.singleNumber(test3) << endl; // Output: 1

    return 0;
}
