#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int sz = nums.size();
        int j = 0;

        for (int i = 1; i < sz; ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                ++j;
            }
            else
            {
                nums[i - j] = nums[i];
            }
        }

        return sz - j;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 2, 2, 3, 4, 4, 5};
    
    int new_length = solution.removeDuplicates(nums);

    cout << "New length: " << new_length << endl;
    cout << "Modified array: ";
    for (int i = 0; i < new_length; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
