#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void printNos(int N)
    {
        vector<int>v;
        if(N==0)return;
        v.push_back(N);
        printNos(N-1);
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        return;
    }
};

int main()
{
    int T;
    
    cin>>T;
    
    while(T--)
    {
        int N;
        
        cin>>N;
        Solution ob;
        ob.printNos(N);
        cout << "\n";
    }
    return 0;
}