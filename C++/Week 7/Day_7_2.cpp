#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    // Function to check if a 3x3 grid is a magic square
    bool isMagic(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        // Check if a 3x3 square can fit starting from grid[i][j]
        if (i + 2 < n && j + 2 < m) {
            int col1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
            int col2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
            int col3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
            int row1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
            int row2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
            int row3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
            int dia1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
            int dia2 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];

            // Check if all rows, columns, and diagonals have the same sum
            if (col1 == col2 && col1 == col3 && col1 == row1 && col1 == row2 && col1 == row3 && col1 == dia1 && col1 == dia2) {
                // Check if all numbers in the 3x3 grid are unique and between 1 and 9
                set<int> s{1,2,3,4,5,6,7,8,9};
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        s.erase(grid[i+k][j+l]);
                    }
                }
                return s.empty();
            }
        }
        return false;
    }

    // Function to count the number of magic squares inside the grid
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        // Iterate over all possible starting points for 3x3 grids
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isMagic(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    // Example grid
    vector<vector<int>> grid = {
        {4, 3, 8, 4},
        {9, 5, 1, 9},
        {2, 7, 6, 2}
    };

    // Create an object of the Solution class
    Solution solution;

    // Get the number of magic squares
    int result = solution.numMagicSquaresInside(grid);

    // Print the result
    cout << "Number of magic squares: " << result << endl;

    return 0;
}
