#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumDeletions(std::string s) {
        // Count the total number of 'a' in the string
        int aCount = 0;
        for(auto &ch : s) aCount += (ch == 'a');
        
        // Initialize minimum deletions to a large number
        int minDeletions = INT_MAX;
        int bCount = 0;

        // Iterate through the string
        for(auto &ch : s){
            // Decrease aCount if the current character is 'a'
            aCount -= (ch == 'a');
            // Calculate the minimum deletions required
            minDeletions = std::min(minDeletions, aCount + bCount);
            // Increase bCount if the current character is 'b'
            bCount += (ch == 'b');
        }
        return minDeletions;
    }
};

int main() {
    Solution sol;
    std::string s = "aababbab";
    std::cout << "Minimum deletions: " << sol.minimumDeletions(s) << std::endl;
    return 0;
}
