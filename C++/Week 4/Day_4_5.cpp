#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            if (nums[i] != val) {
                i++;
            } else if (nums[j] == val) {
                j--;
                n--;
            } else if (nums[i] == val && nums[j] != val) {
                swap(nums[i], nums[j]);
                i++;
                j--;
                n--;
            }
        }
        return n;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 2, 3, 4, 3, 5, 6, 3};
    int val = 3;
    
    int new_length = solution.removeElement(nums, val);

    cout << "New length: " << new_length << endl;
    cout << "Modified array: ";
    for (int i = 0; i < new_length; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
