#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void printNos(int N)
    {
        vector<int>v;
        if(N==0)return;
        v.push_back(N);
        printNos(N-1);
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        return;//Your code here
    }
};

//{ Driver Code Starts.
/* Driver program to test printNos */
int main()
{
    int T;
    
    //taking testcases
    cin>>T;
    
    while(T--)
    {
        int N;
        
        //input N
        cin>>N;
        Solution ob;
        //calling printNos() function
        ob.printNos(N);
        cout << "\n";
    }
    return 0;
}