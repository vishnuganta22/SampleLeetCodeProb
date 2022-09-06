#include <iostream>
#include <string>
#include <map>

using namespace std;

/// <summary>
/// 76. Minimum Window Substring
/// </summary>
class Solution {
public:
    string minWindow(string s, string t) {
        string result = "";
        if (t.length() > s.length()) return result;
        int wStart = 0;
        int wEnd = 0;

        map<char, int> tMap;
        int tCount = 0;
        for (int i = 0; i < t.length(); i++) {
            map<char, int>::iterator res = tMap.find(t[i]);
            if (res == tMap.end()) {
                tMap.insert({t[i], 1});
                tCount++;
            }
            else {
                res->second++;
            }
        }

        map<char, int> rMap = tMap;
        int pLength = 0;
        int rCount = tCount;
        for (int i = 0; i < s.length(); i++) {
            map<char, int>::iterator res = rMap.find(s[i]);
            if (res == rMap.end()) {
                wStart++;
                wEnd++;
            }
            else {
                if (res->second <= 0) {

                }
                else {
                    res->second--;
                    if (res->second == 0) {
                        rCount--;
                    }
                }
            }
        }

        if (wEnd > wStart && (wEnd >= s.length() - 1) && (wEnd - wStart) >= t.length()) {
            for (int i = wStart; i < wEnd; i++) {
                result += s[i];
            }
        }
        return result;
    }
};