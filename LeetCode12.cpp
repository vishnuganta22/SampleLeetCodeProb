#include "stdio.h"
#include "string"
#include "stack"

using namespace std;

/// <summary>
/// Interger to Roman
/// </summary>
class Solution {
private:
    string getRoman(int fv, int pv) {
        if (fv == 0) return "";
        string suffix = "";
        string prefix = "";
        int repeat = 0;
        string rs = "";
        switch (pv) {
            case 1:
                if (fv < 4) {
                    repeat = fv;
                    rs = "I";
                }
                else if (fv == 4) {
                    repeat = 1;
                    rs = "I";
                    suffix = "V";
                }
                else if (fv == 5) {
                    prefix = "V";
                }
                else if(fv > 5 && fv < 9) {
                    repeat = fv - 5;
                    rs = "I";
                    prefix = "V";
                }
                else {
                    repeat = 1;
                    rs = "I";
                    suffix = "X";
                }
                break;
            case 10:
                if (fv < 4) {
                    repeat = fv;
                    rs = "X";
                }
                else if (fv == 4) {
                    repeat = 1;
                    rs = "X";
                    suffix = "L";
                }
                else if (fv == 5) {
                    prefix = "L";
                }
                else if (fv > 5 && fv < 9) {
                    repeat = fv - 5;
                    rs = "X";
                    prefix = "L";
                }
                else {
                    repeat = 1;
                    rs = "X";
                    suffix = "C";
                }
                break;
            case 100:
                if (fv < 4) {
                    repeat = fv;
                    rs = "C";
                }
                else if (fv == 4) {
                    repeat = 1;
                    rs = "C";
                    suffix = "D";
                }
                else if (fv == 5) {
                    prefix = "D";
                }
                else if (fv > 5 && fv < 9) {
                    repeat = fv - 5;
                    rs = "C";
                    prefix = "D";
                }
                else {
                    repeat = 1;
                    rs = "C";
                    suffix = "M";
                }
                break;
            case 1000:
                if (fv < 4) {
                    repeat = fv;
                    rs = "M";
                }
                break;
            default:
                break;
        }
        string result = "";
        for (int i = 0; i < repeat; i++) {
            result += rs;
        }
        return prefix + result + suffix;
    }
public:
    string intToRoman(int num) {
        int pv = 1;
        int temp = num;
        string result = "";
        stack<string> stack;
        do {
            int fv = temp % 10;
            stack.push(getRoman(fv, pv));
            temp = temp / 10;
            pv = pv * 10;
        } while (temp > 0);

        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};