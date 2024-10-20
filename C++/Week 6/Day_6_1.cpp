#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &arr) {
       
    
       int n=arr.size();
       
   
        
       int m=arr[0].size();
       
       int left=0;
       int right=m-1;
       
       int top=0;
       int bottom=n-1;
       
       vector<int>ans;
       
        if (n == 0) return ans;
       
       while(top<=bottom && left<=right){
           
           
           
           for(int i=left;i<=right;i++){
               
               ans.push_back(arr[top][i]);
           }
         
           top++;
           
           for(int i=top;i<=bottom;i++){
               
               ans.push_back(arr[i][right]);
               
           }
         
           right--;
           
           
           if(top<=bottom){
           
           for(int i=right;i>=left;i--){
               ans.push_back(arr[bottom][i]);
           }
           
        bottom--;
           }
         
         
         if(left<=right){
           for(int i=bottom;i>=top;i--){
               ans.push_back(arr[i][left]);
           }
           
              left++;
         }
    
       }
       return ans;
       
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}