#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.

    int findUncompleted(vector<bool>& don, int j, int n){
        for(int i=j; i>n; i--){
            if(don[i]==false)
                return i;
        }
        return -1;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int mxdead = 0;
        vector<pair<int, int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({arr[i].profit, arr[i].dead});
            mxdead = max(mxdead, arr[i].dead);
        }
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        vector<bool>don(mxdead, false);
        int count = 0, prof = 0;
        int fillUntil = 0;
        for(int i=0; i<n; i++){
            int dad = vec[i].second;
            int profi = vec[i].first;
            if(!don[dad]){
                don[dad] = true;
                count++;
                prof += profi;
            }
            else{
                if(dad <= fillUntil){
                    continue;
                }
                int done = findUncompleted(don, dad-1, fillUntil);
                if(done!=-1){
                    don[done] = true;
                    count++;
                    prof += profi;
                }
                else{
                    fillUntil = max(fillUntil, dad);
                }
            }
        }
        return {count, prof};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}

