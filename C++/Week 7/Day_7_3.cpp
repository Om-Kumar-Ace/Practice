#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> &arr, int k) {
    int n = arr.size(); // size of the square matrix
    
    // Calculate effective rotations
    k = k % n;
    
    // Initialize the result matrix
    vector<vector<int>> result(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i) {
        // Rotate the i-th row
        for (int j = 0; j < n; ++j) {
            result[i][(j + k) % n] = arr[i][j];
        }
    }
    
    return result;
}
int main() {
    int n = 3; // Example size of matrix
    int k = 2; // Example number of rotations

    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> result = solve(arr, k);

    // Print the result matrix
    for (const auto &row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
