#include<iostream>
#include<string>
#include<stack>

using namespace std;

/// <summary>
/// 20. Valid Parentheses
/// </summary>

class Solution {
private:
    bool isClose(char f, char s){
        if (f == '(' && s == ')') return true;
        if (f == '[' && s == ']') return true;
        if (f == '{' && s == '}') return true;
        return false;
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (st.size() > 0 && isClose(st.top(), c)) {
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        return st.size() == 0;
    }
};