#include <iostream>
using namespace std;

int main() {
    int arr[20];

    // Initialize the array with numbers 1 to 20
    for (int i = 0; i < 20; i++) {
        arr[i] = i + 1;
    }

    // Print the pattern
    int start = 0, end = 16;

    for (int row = 4; row >= 1; row--) {
        // Print tabs for indentation
        for (int space = 4 - row; space > 0; space--) {
            cout << "\t";  // Use tab for consistent alignment
        }

        // Print the first half of the row
        for (int i = 0; i < row; i++) {
            cout << arr[start++] << "\t";
        }

        // Print the second half of the row
        for (int i = 0; i < row; i++) {
            cout << arr[end++] << "\t";
        }

        // Move the end index back accordingly
        end -= (row * 2 - 1);

        cout << endl;
    }

    return 0;
}
