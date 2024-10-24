class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        for(int x: arr){
            x%=k;
            if (x<0) x+=k;
            freq[x]++;
        }

        if (k%2==0 && freq[k/2]%2!=0) return 0;;
        for(int i=1; i<=k/2; i++)
            if (freq[i]!=freq[k-i]) return 0;
        return 1;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();