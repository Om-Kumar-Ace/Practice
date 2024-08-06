#include <bits/stdc++.h>
using namespace std;

string morseToEnglish(string morsecode)
{
    vector<string> morseList = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.", "--.-", ".-.", "...", "-", "..-", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
    unordered_map<string, char> morseToChar;

    for (int i = 0; i < morseList.size(); ++i)
    {
        if (i < 26)
        {
            morseToChar[morseList[i]] = 'a' + i;
        }
        else
        {
            morseToChar[morseList[i]] = '0' + (i - 26);
        }
    }

    stringstream ss(morsecode);
    string morse;
    string result = "";

    while (ss >> morse)
    {
        result += morseToChar[morse];
    }

    return result;
}

int main()
{
    string morsecode = "... --- ...";
    cout << morseToEnglish(morsecode) << endl; // Output: sos
    return 0;
}
