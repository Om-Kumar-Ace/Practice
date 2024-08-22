#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangle(vector<int>& heights) {
    stack<int> s;
    int max_area = 0;
    int index = 0;

    while (index < heights.size()) {
        // Push index to stack if the current height is greater than or equal to the stack's top
        if (s.empty() || heights[index] >= heights[s.top()]) {
            s.push(index++);
        } else {
            // Pop the top element
            int top_of_stack = s.top();
            s.pop();
            // Calculate the area with heights[top_of_stack] as the smallest height
            int area = heights[top_of_stack] * (s.empty() ? index : index - s.top() - 1);
            // Update max_area
            max_area = max(max_area, area);
        }
    }

    // Remaining elements in the stack
    while (!s.empty()) {
        int top_of_stack = s.top();
        s.pop();
        int area = heights[top_of_stack] * (s.empty() ? index : index - s.top() - 1);
        max_area = max(max_area, area);
    }

    return max_area;
}
