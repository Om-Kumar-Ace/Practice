class Solution {
public:
    void solve(vector<int>& candidates, int &sum, vector<vector<int>> &     output, vector<int> &ans, int i, int target){

	if(sum==target){
        output.push_back(ans);
        return;
    }

    if(i>=candidates.size() || sum+candidates[i]>target)
        return;

    sum+=candidates[i];
    ans.push_back(candidates[i]);
    solve(candidates, sum, output, ans, i+1, target);
    ans.pop_back();
    sum-=candidates[i];
    while(i+1<candidates.size() && candidates[i]==candidates[i+1] )
        i++;
    solve(candidates, sum, output, ans, i+1, target);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)    {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> output;
        vector<int> ans;
        int sum=0;
	    solve(candidates, sum,  output,  ans,  0, target);
	    return output;
    }
};