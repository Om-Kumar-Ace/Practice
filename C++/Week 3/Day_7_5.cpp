#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& v, int k) {
        if (v.empty()) {
            return -1;
        }

        int low = 0;
        int high = v.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2; 
            if (v[mid] == k) {
                return mid;
            } else if (v[mid] > k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }
};

int main() {
    vector<int> v = {2, 5, 8, 12, 16};
    int k = 8;

    Solution solution;
    int index = solution.search(v, k);

    if (index != -1) {
        cout << "Element " << k << " found at index " << index << endl;
    } else {
        cout << "Element " << k << " not found in the vector" << endl;
    }

    return 0;
}