#include <iostream>
#include <vector>
#include <map>

using namespace std;

/// <summary>
/// 15. 3Sum
/// Test Case 1 : [-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
/// Test Case 2 : [0, 0, 0]
/// Test Case 3 : [0, 0, 0]
/// </summary>

class Solution {
private:
    void merge(vector<int>& nums, int const left, int const mid, int const right)
    {
        auto const subArrayOne = mid - left + 1;
        auto const subArrayTwo = right - mid;

        auto* leftArray = new int[subArrayOne],
            * rightArray = new int[subArrayTwo];

        for (auto i = 0; i < subArrayOne; i++)
            leftArray[i] = nums[left + i];
        for (auto j = 0; j < subArrayTwo; j++)
            rightArray[j] = nums[mid + 1 + j];

        auto indexOfSubArrayOne = 0,
            indexOfSubArrayTwo = 0;
        int indexOfMergedArray = left;


        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                nums[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else {
                nums[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }

        while (indexOfSubArrayOne < subArrayOne) {
            nums[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }

        while (indexOfSubArrayTwo < subArrayTwo) {
            nums[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
    }

    void mergeSort(vector<int>& nums, int const begin, int const end)
    {
        if (begin >= end)
            return;

        auto mid = begin + (end - begin) / 2;
        mergeSort(nums, begin, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, begin, mid, end);
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        if (nums.size() < 3) return result;

        mergeSort(nums, 0, nums.size() - 1);

        //Mapping Frequency
        map<int, int> fMap;
        for (int i = 0; i < nums.size(); i++) {
            auto itr = fMap.find(nums.at(i));
            if (itr != fMap.end()) {
                itr->second++;
            }
            else {
                fMap.insert({ nums.at(i) , 1});
            }
        }

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            int target = 0 - nums.at(i);
            do {
                int sum = nums.at(left) + nums.at(right);
                if (sum > target) {
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    vector<int> v;
                    v.push_back(nums.at(i));
                    v.push_back(nums.at(left));
                    v.push_back(nums.at(right));
                    result.push_back(v);
                    bool isFailed = true;
                    auto itrL = fMap.find(nums.at(left));
                    auto itrR = fMap.find(nums.at(right));
                    if (itrL->second > 1) {
                        if (nums.at(i) == nums.at(left)) {
                            left = left + itrL->second - 1;
                        }
                        else {
                            left = left + itrL->second;
                        }
                        isFailed = false;
                    }
                    if (itrR->second > 1) {
                        if (nums.at(i) == nums.at(right)) {
                            right = right - itrR->second - 1;
                        }
                        else {
                            right = right - itrR->second;
                        }
                        isFailed = false;
                    }
                    if (isFailed) left++;
                }
            } while (left < right);
            auto itr = fMap.find(nums.at(i));
            if (itr->second > 1) {
                i = i + itr->second - 1;
            }
        }

        return result;
    }
};