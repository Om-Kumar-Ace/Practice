#include <bits/stdc++.h> 
using namespace std;

void sortTuples(vector<vector<int>>& arr) {
    // Custom comparator to sort based on the last element of the tuple
    auto comparator = [](const vector<int>& a, const vector<int>& b) {
        return a.back() < b.back(); // Compare the last elements
    };

    // Use stable_sort to maintain relative order in case of ties
    stable_sort(arr.begin(), arr.end(), comparator);
}

int main() {
    int T;
    cin >> T; // Number of test cases
    
    while (T--) {
        int N, L;
        cin >> N >> L; // Read N and L
        
        vector<vector<int>> arr(N, vector<int>(L));
        
        // Read the tuples
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < L; ++j) {
                cin >> arr[i][j];
            }
        }
        
        // Sort the tuples
        sortTuples(arr);
        
        // Output the sorted tuples
        for (const auto& tuple : arr) {
            for (int val : tuple) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
