#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> map;

        for(int i = 0; i < arr.size(); i++){
            if(map.find(arr[i]) != map.end()){
                map[arr[i]] = -1;
            } else {
                map[arr[i]] = i;
            }
        }

        vector<int> indexes;
        for(auto pa: map){
            if(pa.second != -1){
                indexes.push_back(pa.second);
            }
        }

        sort(indexes.begin(), indexes.end());
        if(indexes.size() < k) return "";
        return arr[indexes[k-1]];
    }
};

int main() {
    Solution solution;
    vector<string> arr = {"a", "b", "a", "c", "b", "d", "e"};
    int k = 3;
    string result = solution.kthDistinct(arr, k);
    if (!result.empty()) {
        cout << "The " << k << "rd distinct element is: " << result << endl;
    } else {
        cout << "There is no " << k << "rd distinct element." << endl;
    }
    return 0;
}
