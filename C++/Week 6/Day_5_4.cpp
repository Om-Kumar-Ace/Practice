#include <vector>
#include <iostream>

class Solution {
private:
    std::vector<int> row, col, block;

    int find_b(int r, int c) {
        int b = 0;
        if (r > 2) b++;
        if (r > 5) b++;
        if (c > 2) b += 3;
        if (c > 5) b += 3;
        return b;
    }

    void setValues(int r, int c, int val) {
        row[r] = (row[r] | (1 << val));
        col[c] = (col[c] | (1 << val));
        int b = find_b(r, c);
        block[b] = (block[b] | (1 << val));
    }

    bool solve(std::vector<std::vector<char>>& board, int r, int c) {
        if (c == 9) {
            c = 0;
            r++;
        }
        if (r == 9) return true;
        if (board[r][c] != '.') return solve(board, r, c + 1);

        int b = find_b(r, c);
        for (int val = 1; val <= 9; val++) {
            if ((row[r] & (1 << val)) != 0 || (col[c] & (1 << val)) != 0 || (block[b] & (1 << val)) != 0)
                continue;

            int r1 = row[r], c1 = col[c], b1 = block[b];
            setValues(r, c, val);
            board[r][c] = '0' + val;

            bool flag = solve(board, r, c + 1);
            if (flag) return true;

            board[r][c] = '.';
            row[r] = r1, col[c] = c1, block[b] = b1;
        }
        return false;
    }

public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        row.resize(9, 0);
        col.resize(9, 0);
        block.resize(9, 0);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                setValues(i, j, board[i][j] - '0');
            }
        }
        solve(board, 0, 0);
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solution.solveSudoku(board);

    for (const auto& row : board) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
