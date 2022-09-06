#include<iostream>
#include<string>
#include<vector>

using namespace std;

/// <summary>
/// 165. Compare Version Numbers
/// </summary>
/// 
/// t1 { 1.1, 1.10 }
/// t2 {7.5.2.4, 7.5.3}
/// t3 {1.01, 1.001}
/// t4 {1.0, 1.0.0}
/// t5 {0.1, 1.1}

class Solution {
private:
    vector<int> getAllRevisions(string version) {
        vector<int> vec;
        int value = 0;
        bool isStarted = false;
        for (int i = 0; i < version.length(); i++) {
            int v = (int)version[i];

            if (v == 46) {
                vec.push_back(value);
                value = 0;
                isStarted = false;
                continue;
            }

            if (!isStarted && v == 48) {
                continue;
            }

            isStarted = true;
            value = (value * 10) + (v - 48);
        }
        vec.push_back(value);
        return vec;
    }
   
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = getAllRevisions(version1);
        vector<int> v2 = getAllRevisions(version2);

        int n;
        if (v1.size() > v2.size()) {
            n = v1.size();
        }
        else {
            n = v2.size();
        }

        int s1 = v1.size();
        int s2 = v2.size();
        for (int i = 0; i < n; i++) {
            int l1 = i < s1 ? v1.at(i) : 0;
            int l2 = i < s2 ? v2.at(i) : 0;
            
            if (l1 > l2) return 1;
            else if (l1 < l2) return -1;
        }
        return 0;
    }
};