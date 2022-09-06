#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// Roman to Integer
/// </summary>
class Solution {
private:
    int getRomanValue(char c) {
        switch (c)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
public:
    int romanToInt(string s) {
        int n = s.length();
        int result = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            int v = getRomanValue(s[i]);
            result += v;
            if (prev < v) result -= 2 * prev;
            prev = v;
        }
        return result;
    }
};