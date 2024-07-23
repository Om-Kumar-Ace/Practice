#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums;

        vector<int> ans;
        unordered_map<int, int> mp;
        
        // Count the frequency of each element
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        // Use a priority queue to sort based on frequency and value
        priority_queue<pair<int, int>> pq;
        for (auto it : mp) {
            pq.push({-it.second, it.first});
        }

        // Extract elements from the priority queue and build the result
        while (!pq.empty()) {
            for (int i = 0; i < -(pq.top().first); i++) {
                ans.push_back(pq.top().second);
            }
            pq.pop();
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 2, 2, 3};
    vector<int> sortedNums = solution.frequencySort(nums);
    
    cout << "Sorted by frequency: ";
    for (int num : sortedNums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
