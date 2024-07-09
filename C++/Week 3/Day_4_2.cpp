#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        long int m = x;
        long int c = 0;
        while (m != 0)
        {
            c = c * 10 + m % 10;
            m = m / 10;
        }
        if (c == x && x >= 0)
        {
            return true;
        }
        else
            return false;
    }
};

int main()
{
    Solution solution;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (solution.isPalindrome(num))
    {
        cout << num << " is a palindrome." << endl;
    }
    else
    {
        cout << num << " is not a palindrome." << endl;
    }

    return 0;
}