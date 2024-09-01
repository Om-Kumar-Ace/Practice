#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int balance = 0;
    int count = 0;

    for (char c : s) {
        if (c == 'L') {
            balance++;
        } else if (c == 'R') {
            balance--;
        }

        if (balance == 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
