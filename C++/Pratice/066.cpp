#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    string str;
    
    getline(cin, str);
    
    vector<string> words;
    
    stringstream ss(str);
    string word;
    
    while (ss >> word) {
        words.push_back(word);
    }
    
    if (words.size() >= 3) {
        cout << words[words.size() - 3] << endl;
    }
    
    return 0;
}
