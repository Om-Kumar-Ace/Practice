class Solution {
public:
    std::vector<int> missingRolls(std::vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totalSum = mean * (m + n);
        int rollsSum = 0;
        
        for (int roll : rolls) {
            rollsSum += roll;
        }
        
        int missingSum = totalSum - rollsSum;
        
        if (missingSum < n || missingSum > 6 * n) {
            return {};
        }
        
        std::vector<int> result(n);
        int quotient = missingSum / n;
        int remainder = missingSum % n;
        
        for (int i = 0; i < n; i++) {
            result[i] = quotient + (i < remainder ? 1 : 0);
        }
        
        return result;
    }
};
static const int ktkdvshrm = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
