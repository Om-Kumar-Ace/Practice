#include <bits/stdc++.h> 
int countAP(int n, vector<int> A)
{
    // Write your code here. 
    if(n<3) return 0;
    int count =0;
    vector<unordered_map<int,int>>dp(n);
    for(int j=1;j<n;j++){
      for (int i = 0; i < j; i++) {
      long long diff = (long long)A[j]-(long long)A[i];
      if(diff<INT_MIN||diff>INT_MAX)continue;
      int d =(int)diff;
      int count_ij=dp[i].count(d)?dp[i][d]:0;
      dp[j][d]+=count_ij+1;
      count+=count_ij;
      }
    }  
    return  count;
}