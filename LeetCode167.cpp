#include <iostream>
#include <vector>
#include <map>

using namespace std;

/// <summary>
/// 167. Two Sum II - Input Array Is Sorted
/// Test Case 1 : numbers = [2,7,11,15], target = 9
/// Test Case 2 : numbers = [2,3,4], target = 6
/// Test Case 3 : numbers = [-1,0], target = -1
/// </summary>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> resultV;
        if (numbers.size() > 0) {
            do {
                int i = numbers.at(left);
                int j = numbers.at(right);
                int result = i + j;
                if (result < target) {
                    left++;
                }
                else if (result > target) {
                    right--;
                }
                else {
                    resultV.push_back(left + 1);
                    resultV.push_back(right + 1);
                    return resultV;
                }
            } while (left < right);
        }
        return resultV;
    }
};