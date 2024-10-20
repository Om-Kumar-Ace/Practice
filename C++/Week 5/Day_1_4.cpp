#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    long long sumOfSeries(long long n) {
        if(n==1)
            return 1;
        return n*n*n+sumOfSeries(n-1);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.sumOfSeries(N) << "\n";
    }
}