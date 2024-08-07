#include <bits/stdc++.h>
using namespace std;

int sumOfProperDivisors(int num) {
    if (num <= 1) return 0;
    int sum = 1;  
    int sqrtNum = sqrt(num);
    for (int i = 2; i <= sqrtNum; ++i) {
        if (num % i == 0) {
            if (i == (num / i)) {
                sum += i;
            } else {
                sum += i + (num / i);
            }
        }
    }
    return sum;
}

bool amicablePair(int x, int y) {
    return (sumOfProperDivisors(x) == y && sumOfProperDivisors(y) == x);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int X, Y;
        cin >> X >> Y;
        if (amicablePair(X, Y)) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
    return 0;
}
