#include <iostream>
#include <string>
#include <stack>

using namespace std;

/// <summary>
/// Integer to English Words
/// </summary>
class Solution {
private:
    string getSingleDigitValue(int fv) {
        switch (fv)
        {
        case 1:
            return "One";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        default:
            return "";
        }
    }
    string getTwoDigitValue(int fv) {
        switch (fv)
        {
        case 1:
            return "Ten";
        case 2:
            return "Twenty";
        case 3:
            return "Thirty";
        case 4:
            return "Forty";
        case 5:
            return "Fifty";
        case 6:
            return "Sixty";
        case 7:
            return "Seventy";
        case 8:
            return "Eighty";
        case 9:
            return "Ninety";
        default:
            return "";
        }
    }

    string getPlaceValue(int pv) {
        switch (pv)
        {
        case 3:
        case 4:
        case 5:
            return "Thousand";
        case 6:
        case 7:
        case 8:
            return "Million";
        case 9:
        case 10:
            return "Billion";
        default:
            return "";
        }
    }

    string getTeens(int fv) {
        switch (fv)
        {
        case 1:
            return "Eleven";
        case 2:
            return "Twelve";
        case 3:
            return "Thirteen";
        case 4:
            return "Fourteen";
        case 5:
            return "Fifteen";
        case 6:
            return "Sixteen";
        case 7:
            return "Seventeen";
        case 8:
            return "Eighteen";
        case 9:
            return "Nineteen";
        default:
            return "";
        }
    }
public:
    string numberToWords(int num) {
        int temp = num;
        if (num == 0) return "Zero";
        if (num < 10) return getSingleDigitValue(num);

        stack<int> numStack;
        do {
            int fv = temp % 10;
            numStack.push(fv);
            temp = temp / 10;
        } while (temp != 0);

        //23,123
        string result = "";
        int i = 0;
        int size = numStack.size();
        int x = 0;
        while (!numStack.empty()) {
            int p = numStack.size() % 3;
            int k = numStack.top();
            numStack.pop();
            i++;
            x = x * 10 + k;
            if (p == 1) {
                string r = getSingleDigitValue(k);
                if (r.length() > 0) result.length() > 0 ? result += " " + r : result += r;
            }
            else if (p == 2) {
                if (k == 1 && numStack.top() != 0) {
                    string r = getTeens(numStack.top());
                    if (r.length() > 0) result.length() > 0 ? result += " " + r : result += r;
                    numStack.pop();
                    i++;
                }
                else {
                    string r = getTwoDigitValue(k);
                    if (r.length() > 0) {
                        result.length() > 0 ? result += " " + r : result += r;
                    }
                }
            }
            else {
                string r = getSingleDigitValue(k);
                if (r.length() > 0) result.length() > 0 ? result += " " + r + " Hundred" : result += r + " Hundred";
            }
            if (numStack.size() > 0 && (size - i) % 3 == 0) {
                if ((size - i) % 3 == 0 && x > 0) {
                    string suffix = getPlaceValue(numStack.size());
                    if (suffix.length() > 0) result += " " + suffix;
                    x = 0;
                }
            }
        }
        return result;
    }
};