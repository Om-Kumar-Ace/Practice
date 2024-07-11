#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;  // Left pointer starting from the leftmost edge
        int right = height.size() - 1;  // Right pointer starting from the rightmost edge
        int maxWater = 0;  // Initialize the maximum water capacity
        
        while (left < right) {
            // Calculate the width of the container
            int width = right - left;
            
            // Calculate the height of the container (the minimum height between the two lines)
            int h = std::min(height[left], height[right]);
            
            // Calculate the water capacity of the current container
            int water = width * h;
            
            // Update the maximum water capacity if the current container holds more water
            maxWater = std::max(maxWater, water);
            
            // Move the pointers towards each other
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};

int main() {
    Solution sol;
    std::vector<int> height = {1,8,6,2,5,4,8,3,7}; // Example input
    
    int result = sol.maxArea(height);
    
    std::cout << "The maximum area of water that can be contained is: " << result << std::endl;
    
    return 0;
}
