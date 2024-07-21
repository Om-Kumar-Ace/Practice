#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
       vector<long long>ans;
      
      long long val=1;
      long long k=1;
      
      while(k<=n){
          k=fn(val);
          if(k<=n) ans.push_back(k);
          else break;
          val++;
      }
      return ans;
    }
    
    long long fn(long long n){
        if(n==1)return 1;
        return n*fn(n-1);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}