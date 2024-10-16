#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
         //approach using Set
        int mp[26] = {0};
        string ans = "";
        for (auto &it : str) {
            if (mp[it - 'a'] == 0) {
                ans += it;
                mp[it - 'a'] = 1;
            }
        }
        return ans; //convert StringBuilder into string
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}