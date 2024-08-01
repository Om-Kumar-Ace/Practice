#include <bits/stdc++.h> 
using namespace std;

void sortArray(vector<int>& arr, int n) {
    int low = 0; // Boundary for 0s
    int mid = 0; // Current element to examine
    int high = n - 1; // Boundary for 2s
    
    // Process elements until the mid pointer surpasses the high pointer
    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                // Swap 0 with the low boundary, increment both low and mid
                swap(arr[low], arr[mid]);
                low++;
                mid++;
                break;
            case 1:
                // 1 is in the correct place, move mid forward
                mid++;
                break;
            case 2:
                // Swap 2 with the high boundary, decrement high
                swap(arr[mid], arr[high]);
                high--;
                break;
        }
    }
}

int main() {
    vector<int> arr = {2, 0, 1, 1, 0, 2, 0, 1, 2};
    int n = arr.size();
    sortArray(arr, n);
    
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
