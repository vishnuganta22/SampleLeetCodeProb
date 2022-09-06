#include <iostream>
#include <iterator>
#include <set>

using namespace std;

/// <summary>
/// Longest Substring Without Repeating Characters 
/// </summary>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;

        int sLength = s.length();
        int result = 0;

        if (sLength <= 0) return result;

        for (int i = 0; i < sLength; i++) {
            st.clear();
            int j = i;
            while (j < sLength && st.find(s[j]) == st.end()) {
                st.insert(s[j]);
                j++;
            }
            if (st.size() > result) result = st.size();
        }
        return result;
    }
};