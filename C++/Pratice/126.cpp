#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int minSwaps(string s) {

        // stack<char> st;
        // int minCount = 0;

        // for (char ch:s) {
        //     if (ch == '['){
        //         st.push(ch);
        //     }else {

        //         if (!st.empty() && st.top() == '[') {
        //             st.pop();
        //         }else {
        //             st.push(ch);
        //         }
        //     }
        // }

        // // while (!st.empty()) {
        // //     char a = st.top(); st.pop();
        // //     char b = st.top(); st.pop();

        // //     if (a==b)
        // //         minCount++;
        // //     else
        // //         minCount+=2;
        // // }
        // // return minCount/2;

        // int unMatched = st.size();

        // return (unMatched/2 +1) / 2;
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int lb=0;
        int moves=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==']')
            {
                if(lb==0)
                {
                    moves++;
                    lb++;
                }
                else
                {
                    lb--;
                }
            }
            else
            {
                lb++;
            }
        }

        return moves;


    }
};