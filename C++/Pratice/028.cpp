#include <bits/stdc++.h>

void posAndNeg(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pos, neg;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    int i = 0, j = 0, k = 0;

    while (k < n) {
        if (k % 2 == 0) {
            arr[k++] = pos[i++];
        } else {
            arr[k++] = neg[j++];
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        posAndNeg(arr);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}