//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution{
    public:
    long long trappingWater(int arr[], int n){
     vector<pair<int,int>>vmx(n, {0,0});
     int mx=-1;
     for(int i=n-1; i>=0; i--){
         if(i==n-1){
             vmx[i].second=mx;  
             mx=arr[i];
         }else{
             if(arr[i]>mx){
                 mx=arr[i];
             }
              vmx[i].second=mx; 
         }
     }
     
     mx=-1;
     for(int i=0; i<n; i++){
         if(i==0){
            vmx[i].first=mx; 
            mx=arr[i];
         }else{
             if(arr[i]>mx){
                 mx=arr[i];
             }
             vmx[i].first=mx; 
         }
      }
      
    //   for(int i=0; i<n; i++){
    //       cout<<vmx[i].first<<" "<<vmx[i].second;
    //       cout<<endl;
    //   }
      
      long long sum=0;
      for(int i=0; i<n; i++){
          if(vmx[i].first==-1||vmx[i].second==-1){
              continue;
          }else{
              int val=min(vmx[i].first,vmx[i].second);
            //   cout<<val;
              val-=arr[i];
              if (val > 0)
              sum+=val;
          }
      }
      
      return sum;
  }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}