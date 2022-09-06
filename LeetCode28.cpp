#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// Implement strStr()
/// </summary>

class Solution {
private:
    // Time Limit execeded for this
    int bruteForce(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        for (int i = 0; i < haystack.length(); i++) {
            for (int j = 0; j < needle.length(); j++) {
                if (haystack[i + j] != needle[j]) break;
                if (j == needle.length() - 1) return i;
            }
        }
        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        if (needle.length() > haystack.length()) return -1;
        for (int i = 0; i < (haystack.length() - needle.length() + 1); i++) {
            int t = 0;
            for (int j = 0; j < needle.length(); j++) {
                if (haystack[i + j] != needle[j]) {
                    if (t != 0) i = i + t - 1;
                    break;
                }
                if (t == 0 && needle[0] == haystack[i + j]) t = j;
                if (j == needle.length() - 1) return i;
            }
        }
        return -1;
    }
};