#include<iostream>
#include<fstream>

using namespace std;

int main(){
    string st;
    // Opening files using constructor and reading it
    ifstream in("Day_1_2.txt"); // Read operation
    // in>>st;
    getline(in, st);  
    cout<<st;

    return 0;
}
