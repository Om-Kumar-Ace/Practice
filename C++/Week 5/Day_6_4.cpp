#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // Function to merge two sorted subarrays into a single sorted array
    void merge(vector<int>& A, int start, int mid, int end, vector<int>& buff) {
        int left = start, right = mid + 1;
        int s = end - start + 1;

        for(int i = 0; i < s; i++) {
            int i0 = start + i;
            if(left > mid) {
                buff[i0] = A[right];
                right++;
            } else if(right > end) {
                buff[i0] = A[left];
                left++;
            } else if(A[left] < A[right]) {
                buff[i0] = A[left];
                left++;
            } else {
                buff[i0] = A[right];
                right++;
            }
        }

        for(int i = start; i < start + s; i++) 
            A[i] = buff[i];
    }

    // Function to perform merge sort on the array
    void mergeSort(vector<int>& A, int start, int end, vector<int>& buff) {
        if(end <= start) return;
        
        int mid = start + (end - start) / 2;
        
        mergeSort(A, start, mid, buff);
        mergeSort(A, mid + 1, end, buff);
        merge(A, start, mid, end, buff);
    }

    // Function to sort the array
    vector<int> sortArray(vector<int>& nums) {
        vector<int> buff(nums.size());
        mergeSort(nums, 0, nums.size() - 1, buff);
        return nums;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 2, 3, 1};

    vector<int> sortedArray = solution.sortArray(nums);
    for(int num : sortedArray) {
        cout << num << " ";
    }

    return 0;
}
