#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void printGfg(int N) {
        // Code he
         if(N<=0){
            return;
        }
        cout<<"GFG ";
        N--;
        printGfg(N);
    }
};


int main() {
    int T;

    cin >> T;

    while (T--) {
        int N;

        cin >> N;
        Solution ob;
        ob.printGfg(N);
        cout << "\n";
    }
    return 0;
}
