#include <iostream>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) return 0; // if needle is an empty string, return 0
        int i, count;
        for (i = 0; i <= haystack.length() - needle.length(); i++) {
            count = 0; // variable to check if all letters in needle string are found
            if (haystack[i] == needle[0]) { // check if the character is equal to first character in needle
                for (int j = 0; j < needle.length(); j++) { // loop to iterate through needle string and check the matching
                    if (haystack[i + j] == needle[j]) { // if the letter is matched increment the count and move to check next letter
                        count++; // the number of letters matched
                    } else {
                        break;
                    }
                }
                if (count == needle.length()) { // if all letters are found then return the index location
                    return i;
                }
            }
        }
        return -1; // no match was found
    }
};

int main() {
    Solution solution;
    std::string haystack = "hello";
    std::string needle = "ll";
    int index = solution.strStr(haystack, needle);
    std::cout << "The index of the first occurrence of \"" << needle << "\" in \"" << haystack << "\" is: " << index << std::endl;

    haystack = "aaaaa";
    needle = "bba";
    index = solution.strStr(haystack, needle);
    std::cout << "The index of the first occurrence of \"" << needle << "\" in \"" << haystack << "\" is: " << index << std::endl;

    haystack = "";
    needle = "";
    index = solution.strStr(haystack, needle);
    std::cout << "The index of the first occurrence of \"" << needle << "\" in \"" << haystack << "\" is: " << index << std::endl;

    return 0;
}
