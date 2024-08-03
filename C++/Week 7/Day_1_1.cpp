#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return arr == target;
    }
};

int main() {
    Solution sol;
    vector<int> target = {1, 2, 3, 4};
    vector<int> arr = {2, 4, 1, 3};
    
    bool result = sol.canBeEqual(target, arr);
    if (result) {
        cout << "The two arrays can be made equal." << endl;
    } else {
        cout << "The two arrays cannot be made equal." << endl;
    }

    return 0;
}
