#include <bits/stdc++.h>
#include <vector> 
using namespace std;

// Function to convert the 2D matrix to a 1D vector in waveform pattern
vector<int> rowWaveForm(vector<vector<int>> &mat) {
    vector<int> result;
    int n = mat.size();     // Number of rows
    int m = mat[0].size();  // Number of columns
    
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            // Traverse from left to right for even-indexed rows
            for (int j = 0; j < m; ++j) {
                result.push_back(mat[i][j]);
            }
        } else {
            // Traverse from right to left for odd-indexed rows
            for (int j = m - 1; j >= 0; --j) {
                result.push_back(mat[i][j]);
            }
        }
    }
    return result;
}

int main() {
    // Example matrix
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    // Get the waveform result
    vector<int> result = rowWaveForm(mat);
    
    // Print the result
    cout << "Waveform pattern: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
