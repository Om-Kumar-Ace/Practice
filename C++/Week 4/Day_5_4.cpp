#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
         long long gcdValue=gcd(A,B);
         long long lcmValue=(A*B)/gcdValue;
         return{lcmValue, gcdValue};
        }

        long long gcd(long long a, long long b)
        {
           while(b!=0){
               long long temp=b;
               b=a%b;
               a=temp;
           } 
           return a;
        }
        
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}