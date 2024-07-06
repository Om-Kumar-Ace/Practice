#include<iostream>
#include<fstream>

using namespace std;

int main(){
    string st = "Om Kumar";
    // Opening files using constructor and writing it
    ofstream out("Day_1_1.txt"); // Write operation
    out<<st;

    return 0;
}
