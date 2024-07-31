#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minHeightShelves(std::vector<std::vector<int>>& books, int shelfWidth) {
        int n = books.size();
        std::vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;  // Base case: no books require 0 height
        
        for (int i = 1; i <= n; ++i) {
            int total_width = 0;
            int max_height = 0;
            for (int j = i; j > 0; --j) {
                total_width += books[j-1][0];
                if (total_width > shelfWidth) {
                    break;
                }
                max_height = std::max(max_height, books[j-1][1]);
                dp[i] = std::min(dp[i], dp[j-1] + max_height);
            }
        }
        
        return dp[n];
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> books = {{1, 3}, {2, 4}, {3, 2}};
    int shelfWidth = 6;
    std::cout << "Minimum height of shelves: " << solution.minHeightShelves(books, shelfWidth) << std::endl;
    return 0;
}
