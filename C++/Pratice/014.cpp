#pragma GCC optimize("Ofast")
static auto _ = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr;}();
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int size = bills.size();
        int bill5 = 0;
        int bill10 = 0;
        int i, bill;
        for (i = 0; i < size; i++) {
            bill = bills[i];
            if (bill == 20) {
                if (bill10 > 0) {
                    bill5 -= 1;
                    bill10 -= 1;
                    if (bill5 < 0)
                        break;
                    if (bill10 < 0)
                        break;
                }
                else {
                    bill5 -= 3;
                    if (bill5 < 0)
                        break;
                }
            }
            else if (bill == 10) {
                bill5 -= 1;
                bill10 += 1;
                if (bill5 < 0)
                    break;
            }
            else // if (bill == 5)
                bill5 += 1;
        }
        return bill5 >= 0 && bill10 >= 0;
    }
};