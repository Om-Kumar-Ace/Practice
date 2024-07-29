//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
         int n = arr.size(), m = arr[0].size();
        int maxi = 0, cnt = 0, row = -1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1) cnt++;
            }
            if (maxi < cnt) {
                maxi = cnt;
                row = i;
            }
            cnt = 0;
        }
        return row;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}