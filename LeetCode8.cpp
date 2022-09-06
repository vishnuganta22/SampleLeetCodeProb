#include "stdio.h"
#include "limits.h"
#include "string"

using namespace std;

 /// <summary>
/// String to integer (atoi)
/// </summary>
class Solution {
public:
    int myAtoi(string s) {
        int limit = INT_MAX;
        int n = s.length();

        long result = 0;
        bool isWordStarted = false;
        int sign = 1;
        bool isSignConsumed = false;
        for (int i = 0; i < n; i++) {
            int as = s[i];
            if (as != 32) {
                isWordStarted = true;
                if (as == 45) {
                    if (isSignConsumed) break;
                    sign = -1;
                    isSignConsumed = true;
                }
                else if (as == 43) {
                    if (isSignConsumed) break;
                    isSignConsumed = true;
                }
                else if (as > 47 && as < 58) {
                    isSignConsumed = true;
                    result = result * 10 + (as - 48);
                    if (result > limit) {
                        if (sign == 1) {
                            return limit;
                        }
                        else {
                            return limit * sign - 1;
                        }
                    }
                }
                else {
                    break;
                }
            }
            else {
                if (isWordStarted) break;
            }
        }
        return result * sign;
    }
};