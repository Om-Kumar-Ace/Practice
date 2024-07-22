#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // for memset

// Optimization directives for GCC
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

// Fast input/output
static auto _ = []() noexcept {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

int fre[100001]; // Frequency array

class Solution {
public:
    int maxFrequency(std::vector<int>& nums, int k) {
        const int sz = nums.size();
        if (sz > 1500) {
            memset(fre, 0, sizeof(fre));
            for (auto e : nums) fre[e]++;
            int i = 1;
            while (fre[i] == 0) ++i;
            int pre = i, r = fre[pre], wl = i;
            long long inc = 0, pcnt = r;
            i++;
            while (true) {
                while (i <= 100000 && fre[i] == 0) ++i;
                if (i == 100001) break;
                int cur = i;
                inc += (cur - pre) * pcnt;
                while (inc > k) {
                    while (fre[wl] == 0) wl++;
                    --fre[wl];
                    inc -= cur - wl;
                    --pcnt;
                }
                pcnt += fre[i++];
                r = std::max(r, (int)pcnt);
                pre = cur;
            }
            return r;
        }
        std::sort(nums.begin(), nums.end());
        int i = 1, pre = nums[0];
        while (i < sz && nums[i] == pre) ++i;
        int r = i, wl = 0;
        long long inc = 0, pcnt = i;
        while (i < sz) {
            int cur = nums[i++];
            inc += (cur - pre) * pcnt;
            while (inc > k) { inc -= cur - nums[wl++]; --pcnt; }
            pcnt++;
            while (i < sz && nums[i] == cur) { ++i; ++pcnt; }
            r = std::max(r, i - wl);
            pre = cur;
        }
        return r;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 4, 4, 4, 4, 5, 5, 5, 5, 5};
    int k = 5;
    int result = solution.maxFrequency(nums, k);
    std::cout << "Maximum frequency: " << result << std::endl;
    return 0;
}
