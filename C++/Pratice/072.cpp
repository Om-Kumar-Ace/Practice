//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<string>&arr, vector<vector<int>>&graph,vector<int>& mp,int u){
        
        int l=arr[u].back()-'a';
        
        for(auto&v:graph[l]){
            if(!mp[v]){
                mp[v]=1;
                dfs(arr,graph,mp,v);
            }
        }
        
    }
  
    int isCircle(vector<string> &arr) {
        // code here
        
        vector<vector<int>>graph(26);
        vector<int>mp(arr.size(),0);


        for(int i=0;i<arr.size();i++){
            int f=arr[i][0]-'a';
            graph[f].push_back(i);
        }
        
        mp[0]=1;
        dfs(arr,graph,mp,0);
        for(int i=0;i<arr.size();i++){
            if(!mp[i]){
                return 0;
            }
        }
        
        
        vector<int>toVer(26,0);
        vector<int>fromVer(26,0);
        
        for(int i=0;i<arr.size();i++){
            int f=arr[i][0]-'a';
            int l=arr[i].back()-'a';
            fromVer[f]++;
            toVer[l]++;
        }
        
        for(int i=0;i<26;i++){
            if(fromVer[i]!=toVer[i]){
                return 0;
            }
        }
        
        return 1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends