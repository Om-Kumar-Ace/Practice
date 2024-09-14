//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
    int n = arr.size();
    int i = 0, j;

    while (i < n) {
        // If the element at the correct position (even index -> positive, odd index -> negative)
        if ((i % 2 == 0 && arr[i] >= 0) || (i % 2 != 0 && arr[i] < 0)) {
            i++;
        } 
        // Else, find the next element with the opposite sign
        else {
            j = i + 1;
            while (j < n && ((i % 2 == 0 && arr[j] < 0) || (i % 2 != 0 && arr[j] >= 0))) {
                j++;
            }

            // If we found an element with the opposite sign, rotate elements between i and j
            if (j < n) {
                int temp = arr[j];
                // Shift all elements between i and j to the right
                for (int k = j; k > i; k--) {
                    arr[k] = arr[k-1];
                }
                arr[i] = temp;
            }
            i++;
        }
    }
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends