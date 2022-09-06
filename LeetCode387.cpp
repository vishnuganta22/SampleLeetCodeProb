#include<iostream>
#include<string>
#include<map>

using namespace std;

/// <summary>
/// 387. First Unique Character in a string
/// </summary>

struct Data {
    int p = -1;
    int c = 0;
};

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, Data> rMap;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            auto itr = rMap.find(c);
            if (itr == rMap.end()) {
                struct Data d;
                d.c = 1;
                d.p = i;
                rMap[c] = d;
            }
            else {
                itr->second.c++;
            }
        }

        int result = -1;
        if (rMap.size() > 0) {
            map<char, Data>::iterator it;
            for (it = rMap.begin(); it != rMap.end(); it++)
            {
                //cout<< it->first << " :: " <<it->second.p << " :: " <<  it->second.c << endl;
                if (it->second.c == 1) {
                    if (result == -1) result = it->second.p;
                    if (it->second.p < result) result = it->second.p;
                }
            }
        }
        return result;
    }
};