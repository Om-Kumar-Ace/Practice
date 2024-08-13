#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    long long int floorSqrt(long long int n) {
        long long int l = 1;
        long long int r = n;
        while(l<=r){
          long long int mid = (l+r)/2.0;
          if(mid*mid<n){
              l = mid+1;
          }
          else if(mid*mid>n){
              r = mid-1;
          }
          else return floor(mid);
        }
        return l-1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}