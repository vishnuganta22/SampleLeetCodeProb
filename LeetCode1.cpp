#include<iostream>
#include <vector>
#include <map>

using namespace std;

/// <summary>
/// Two Sum
/// </summary>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        map<int, int> gMap;
        int i = 0;
        int size = nums.size();
        do {
            int n = nums.at(i);
            int r = target - n;
            auto itr = gMap.find(r);
            if (itr != gMap.end()) {
                sol.push_back(i);
                sol.push_back(itr->second);
                return sol;
            }
            else {
                gMap.insert({ n, i });
            }
            i++;
        } while (i < size);
        return sol;
    }
};