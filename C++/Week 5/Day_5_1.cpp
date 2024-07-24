#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> val(n, pair<int, int>(0, 0));

        for (int i = 0; i < n; ++i) { 
            int num = nums[i], j = 0, ans = 0;
            if (num == 0) {
                ans = mapping[num];
            } else {
                while (num > 0) {
                    ans += pow(10, j) * mapping[num % 10];
                    num /= 10;
                    ++j;
                }
            }
            val[i].first = ans;
            val[i].second = i;
        }
        
        sort(val.begin(), val.end());
        vector<int> res(n);

        for (int i = 0; i < n; ++i) { 
            res[i] = nums[val[i].second];
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> mapping = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6}; // example mapping
    vector<int> nums = {990, 332, 981}; // example input

    vector<int> result = solution.sortJumbled(mapping, nums);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
