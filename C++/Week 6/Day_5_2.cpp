#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        if(arr.size()==1){
            return arr[0];
        }
        string ans="";
        int size=min(arr[0].size(),arr[1].size());
            for(int j=0;j<size;j++){
                if(arr[0][j]!=arr[1][j]){
                    break;
                }
                else{
                ans.push_back(arr[0][j]);
                }
            }
            
            for(int i=2;i<arr.size();i++){
                for(int j=0;j<arr[i].size();j++){
                    if(arr[i][j]!=ans[j]){
                        ans=ans.substr(0,j);
                    }
                }
            }
            if(ans.size()==0){
                ans="-1";
            }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}
