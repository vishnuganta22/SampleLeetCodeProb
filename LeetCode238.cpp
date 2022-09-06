#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// 238. Product of Array Except Self
/// Conditions : We shouldn't user divison operator 
/// t1 : {1, 2, 3, 4}
/// t2 : {-1, 1, 0, -3, 3}
/// </summary>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int* pre = new int[nums.size()];
        int* pos = new int[nums.size()];
        int pe = 1;
        int po = 1;
        int j = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            pre[i] = pe;
            pe = pe * nums[i];

            pos[j] = po;
            po = po * nums[j];
            j--;
        }

        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            result.push_back(pre[i] * pos[i]);
        }
        return result;
    }
};