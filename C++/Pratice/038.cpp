#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &mat, vector<vector<int>> &dp, int i, int j, int n, int m) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    // Directions arrays for moving up, down, left, and right
    vector<int> dirX = {0, 1, 0, -1};
    vector<int> dirY = {1, 0, -1, 0};
    
    int maxLength = 1;
    
    for (int k = 0; k < 4; ++k) {
        int newX = i + dirX[k];
        int newY = j + dirY[k];
        
        if (newX >= 0 && newX < n && newY >= 0 && newY < m && mat[newX][newY] > mat[i][j]) {
            maxLength = max(maxLength, 1 + dfs(mat, dp, newX, newY, n, m));
        }
    }
    
    dp[i][j] = maxLength;
    return dp[i][j];
}

int longestIncreasingPath(vector<vector<int>> &mat, int n, int m) {
    if (n == 0 || m == 0) return 0;
    
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxPath = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            maxPath = max(maxPath, dfs(mat, dp, i, j, n, m));
        }
    }
    
    return maxPath;
}

int main() {
    // Example usage
    vector<vector<int>> mat = {
        {1, 2, 3},
        {5, 6, 4},
        {9, 5, 11}
    };
    int n = mat.size();
    int m = mat[0].size();
    
    cout << longestIncreasingPath(mat, n, m) << endl; // Output: 5

    return 0;
}
