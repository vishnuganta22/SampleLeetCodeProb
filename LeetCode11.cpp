#include "stdio.h"
#include "vector"

using namespace std;

/// <summary>
/// Container with most water 
/// </summary>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int left = 0;
        int right = size - 1;
        int ma = INT_MIN;
        do {
            int l = height.at(left);
            int r = height.at(right);
            int h = l < r ? l : r;
            int area = (right - left) * h;
            if (area > ma) ma = area;
            if (l < r) left++;
            else right--;
        } while (left < right);
        return ma;
    }
};