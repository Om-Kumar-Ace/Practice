#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        vector<int> v; 
        int sum = 0;
        v.push_back(0);
        for(int i = 0;i<n;i++){
            sum+=arr[i];
            v.push_back(sum);
        }
        unordered_map<int,vector<int>> ump; 
        for(int i = 0;i<n+1;i++){
            ump[v[i]].push_back(i);
        }
        for(int i = 0;i<n+1;i++){
            v[i] = v[i]+k;
        }
        int maxi = 0;
        for(int i = 0 ;i<n+1;i++){
            for(auto j : ump[v[i]]){
                maxi = max(maxi, (j-i));
            }
        }
        return maxi;
    } 



};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}