#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n; 
    
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    sort(nums.begin(), nums.end());
    
    set<double> averages;
    
    while (!nums.empty()) {
        int min_val = nums.front();
        int max_val = nums.back();
        
        nums.erase(nums.begin());     
        nums.pop_back();             
        
        double avg = (min_val + max_val) / 2.0;
        averages.insert(avg);
    }
    
    cout << averages.size() << endl;
    
    return 0;
}
