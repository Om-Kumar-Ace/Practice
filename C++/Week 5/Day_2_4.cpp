#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int func(int n, vector<int>& dp) {
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = func(n - 1, dp) + func(n - 2, dp);
    }

    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return func(n, dp);
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "The " << n << "th Fibonacci number is: " << solution.fib(n) << endl;
    return 0;
}
