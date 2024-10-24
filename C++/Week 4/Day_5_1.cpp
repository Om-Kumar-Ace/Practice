#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        cout << setprecision(3) << fixed;
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

class Solution
{
public:
    double switchCase(int choice, vector<double> &arr)
    {
        double pi = 3.14159265359;
        switch (choice)
        {
        case 1:
            return pi * pow(arr[0], 2);
            break;
        case 2:
            return arr[0] * arr[1];
            break;
        }
    }
};

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int choice;
        scanf("%d", &choice);

        vector<double> arr(choice);
        Array::input(arr, choice);

        Solution obj;
        double res = obj.switchCase(choice, arr);
        // cout<<fixed<<endl;
        if (res == int(res))
        {
            cout << int(res) << endl;
            continue;
        }
        cout << setprecision(2) << fixed;
        //
        // }else{
        cout << res << endl;
        // }
    }
}