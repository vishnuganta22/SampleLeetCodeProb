#include "stdio.h"
#include "limits.h"

using namespace std;

/// <summary>
/// Reverse Integer
/// </summary>
class Solution {
public:
    int reverse(int x) {
        int t = x;
        int limit = INT_MAX / 10;
        int nLimit = INT_MIN / 10;
        long result = 0;
        do {
            if (result > limit || result < nLimit) return 0;
            result = result * 10 + t % 10;
            t = t / 10;
        } while (t != 0);
        return result;
    }
};