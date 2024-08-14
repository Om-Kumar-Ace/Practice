#include <vector>

int findKthElement(std::vector<std::vector<int>> matrix, int k) {
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    int dir = 0; // 0: right, 1: down, 2: left, 3: up
    int count = 0;

    while (top <= bottom && left <= right) {
        if (dir == 0) {
            for (int i = left; i <= right; i++) {
                count++;
                if (count == k) {
                    return matrix[top][i];
                }
            }
            top++;
        } else if (dir == 1) {
            for (int i = top; i <= bottom; i++) {
                count++;
                if (count == k) {
                    return matrix[i][right];
                }
            }
            right--;
        } else if (dir == 2) {
            for (int i = right; i >= left; i--) {
                count++;
                if (count == k) {
                    return matrix[bottom][i];
                }
            }
            bottom--;
        } else if (dir == 3) {
            for (int i = bottom; i >= top; i--) {
                count++;
                if (count == k) {
                    return matrix[i][left];
                }
            }
            left++;
        }
        dir = (dir + 1) % 4;
    }

    return -1; // If k is larger than the number of elements in the matrix
}