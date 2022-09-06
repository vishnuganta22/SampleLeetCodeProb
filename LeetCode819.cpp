#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/// <summary>
/// Most Common Word
/// </summary>
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int n = paragraph.length();
        string s = "";
        map<string, int> mResult;
        for (int i = 0; i < n; i++) {
            char c = paragraph[i];
            int as = (int)c;

            if (as == 32 || as == 33 || as == 34 || as == 63 || as == 39 || as == 44 || as == 46 || as == 59) {
                if (s.length() > 0) {
                    map<string, int>::iterator it = mResult.find(s);
                    if (it == mResult.end()) {
                        mResult[s] = 1;
                    }
                    else {
                        it->second++;
                    }
                }
                s = "";
            }
            else {
                int t = as;
                if (t > 64 && t < 91) {
                    t += 32;
                }
                s += (char)t;
            }
        }
        if (s.length() > 0) {
            map<string, int>::iterator it = mResult.find(s);
            if (it == mResult.end()) {
                mResult[s] = 1;
            }
            else {
                it->second++;
            }
        }
        s = "";

        int max = INT_MIN;
        string result = "";
        for (map<string, int>::iterator it = mResult.begin(); it != mResult.end(); ++it) {
            if (banned.size() > 0 && std::find(banned.begin(), banned.end(), it->first) != banned.end()) continue;
            if (max < it->second) {
                max = it->second;
                result = it->first;
            }
        }
        return result;
    }
};