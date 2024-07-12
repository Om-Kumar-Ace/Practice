#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 3) {
            return {};
        }
        if (nums[0] > 0) {
            return {};
        }
        vector<vector<int>> answer;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int low = i + 1, high = nums.size() - 1;
            int sum = 0;
            while (low < high) {
                sum = nums[i] + nums[low] + nums[high];
                if (sum > 0) {
                    high--;
                } else if (sum < 0) {
                    low++;
                } else {
                    answer.push_back({nums[i], nums[low], nums[high]});
                    int last_low_occurrence = nums[low], last_high_occurrence = nums[high];
                    while (low < high && nums[low] == last_low_occurrence) {
                        low++;
                    }
                    while (low < high && nums[high] == last_high_occurrence) {
                        high--;
                    }
                }
            }
        }
        return answer;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    vector<vector<int>> result = sol.threeSum(nums);
    cout << "Triplets that sum up to zero:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i < triplet.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
