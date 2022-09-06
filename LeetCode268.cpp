#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// 268. Missing Numbers
/// </summary>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = (n * (n + 1)) / 2;
        int t = 0;
        for (int i = 0; i < n; i++) {
            t += nums.at(i);
        }
        return total - t;
    }
};