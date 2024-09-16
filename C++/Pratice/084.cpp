class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (int i = 0; i<timePoints.size(); i++){
            int hour = (timePoints[i][0] - '0')*10 + timePoints[i][1] - '0';
            int minute = hour*60+(timePoints[i][3] - '0')*10 + timePoints[i][4] - '0';
            
            // cout<<hour<<" "<<minute<<endl;
            minutes.push_back(minute);
        }
        sort(minutes.begin(), minutes.end());
        int ans = INT_MAX;
        for (int i=0; i<minutes.size()-1;i++){
            ans=min(minutes[i+1]-minutes[i],ans);
        }
        ans=min(abs(minutes[0]+1440-minutes[minutes.size()-1]),ans);
        return ans;
    }
};