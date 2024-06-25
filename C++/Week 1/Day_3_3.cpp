#include <iostream>
using namespace std;

int main()
{
    int n;
    // Prompt user to enter a number
    cout << "Enter a number" << endl;
    cin >> n;

    int x;
    cout << "Multiplication table with For loop" << endl;
    // For-Loop
    for (int f = 1; f <= 10; f++)
    {
        x = n * f;
        cout << x << endl;
    }

    int y;
    int w = 1;
    cout << "Multiplication table with While loop" << endl;
    // While-Loop
    while (w <= 10)
    {
        y = n * w;
        cout << y << endl;
        w++;
    }

    int z;
    int d = 1;
    cout << "Multiplication table with Do-While loop" << endl;
    // Do-While Loop
    do
    {
        z = n * d;
        cout << z << endl;
        d++;
    } while (d <= 10);

    return 0;
}
