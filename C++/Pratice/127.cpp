//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int pairsum(vector<int> &arr) {
        // code here
        int maxx1 = INT_MIN;
        for(auto it : arr)
        {
            maxx1 = max(maxx1, it);
        }
        int maxx2 = INT_MIN;
        for(auto it : arr)
        {
            if(it < maxx1)
            {
                maxx2 = max(maxx2, it);
            }
        }
        return maxx1 + maxx2;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends