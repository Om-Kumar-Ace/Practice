#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int maxOne(vector<vector<int>>& arr) {
    int maxCount = 0;
    int rowIndex = -1;
    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; ++i) {
        // Find the first occurrence of 1 in the row using lower_bound
        auto it = std::lower_bound(arr[i].begin(), arr[i].end(), 1);
        // Calculate the number of 1s in this row
        int count = m - (it - arr[i].begin());
        // If this row has more 1s than the current max, update maxCount and rowIndex
        if (count > maxCount) {
            maxCount = count;
            rowIndex = i;
        }
    }

    return rowIndex;
}

int main() {
    vector<vector<int>> arr = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    int result = maxOne(arr);
    if (result != -1) {
        cout << "Row with the maximum number of 1s is: " << result << endl;
    } else {
        cout << "No 1s found in the matrix." << endl;
    }

    return 0;
}
