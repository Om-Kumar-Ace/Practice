#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Search Range
pair<int, int> searchRange(const vector<int>& nums, int target) {
    int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    if (left <= right && nums[left] == target && nums[right] == target)
        return {left, right};
    return {-1, -1};
}

// Find Minimum
int findMin(const vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];
}

// Solution class
class Solution {
public:
    int n, distanceThreshold;
    int dist[100][100];

    void FW(vector<vector<int>>& edges) {
        fill(&dist[0][0], &dist[0][0] + 100 * 100, 1e9);
        for (int i = 0; i < n; i++) 
            dist[i][i] = 0;
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (w <= distanceThreshold) // drop large weights
                dist[u][v] = dist[v][u] = w;
        }
        // Main loop
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        this->n = n;
        this->distanceThreshold = distanceThreshold;
        FW(edges);

        int min_cnt = n, city = -1;
        for (int i = 0; i < n; i++) {
            int cnt = -1;  // i itself doesn't count
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) 
                    cnt++;
            }
            if (cnt <= min_cnt) {
                min_cnt = cnt;
                city = i;
            }
        }
        return city;
    }
};

int main() {
    // Merge Sort Example
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    mergeSort(arr, 0, arr.size() - 1);
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    // Search Range Example
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    pair<int, int> range = searchRange(nums, target);
    cout << "Search range: [" << range.first << ", " << range.second << "]" << endl;

    // Find Minimum Example
    vector<int> rotatedSortedArr = {3, 4, 5, 1, 2};
    int minElement = findMin(rotatedSortedArr);
    cout << "Minimum element: " << minElement << endl;

    // Solution Example
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {2, 0, 4}, {2, 3, 2}};
    int n = 4, distanceThreshold = 4;
    Solution sol;
    int city = sol.findTheCity(n, edges, distanceThreshold);
    cout << "City with the smallest number of reachable cities: " << city << endl;

    return 0;
}

// Initialize IO
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
