class Solution {
    int currMax = INT_MIN / 2;
    int currMin = INT_MAX / 2;
    int maxDiff = 0;
public:
    int maxDistance(vector<vector<int>>& arrays) {
        for(const auto &el: arrays){
            int newMax = el.back();
            int newMin = el[0];
            maxDiff = max(maxDiff, max(newMax - currMin, currMax - newMin));
            currMax = max(currMax, newMax);
            currMin = min(currMin, newMin);
        }
        return maxDiff;
    }
};