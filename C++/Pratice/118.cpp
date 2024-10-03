class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int rem = 0;
        for(int& n : nums) rem = n = (n + rem)%p;
        if(rem == 0) return 0;

        std::unordered_map<int, int> rems;        
        int minLength = nums.size();
        rems[rem] = -1;
        for(int idx = 0; idx < nums.size(); ++idx){
            //check if it's a valid beginning
            if(auto pEnd = rems.find(nums[idx]); pEnd != rems.end()){
                int newLength = idx - pEnd->second;
                if(newLength == 1) return 1; 
                if(minLength > newLength) minLength = newLength;
            }
            //write as end
            int target = nums[idx] + rem;
            if(target > p) target -= p;
            rems[target] = idx;
        }
        return minLength<nums.size() ? minLength : -1;
    }
};

static const int acceleration_hack = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();