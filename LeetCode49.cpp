#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/// <summary>
/// 49. Group Anagrams
/// </summary>
class Solution {
private:
    void merge(string& str, int const left, int const mid, int const right)
    {
        auto const subArrayOne = mid - left + 1;
        auto const subArrayTwo = right - mid;

        auto* leftArray = new char[subArrayOne],
            * rightArray = new char[subArrayTwo];

        for (auto i = 0; i < subArrayOne; i++)
            leftArray[i] = str[left + i];
        for (auto j = 0; j < subArrayTwo; j++)
            rightArray[j] = str[mid + 1 + j];

        auto indexOfSubArrayOne = 0,
            indexOfSubArrayTwo = 0;
        int indexOfMergedArray = left;


        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                str[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else {
                str[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }

        while (indexOfSubArrayOne < subArrayOne) {
            str[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }

        while (indexOfSubArrayTwo < subArrayTwo) {
            str[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
    }

    void mergeSort(string& str, int const begin, int const end)
    {
        if (begin >= end)
            return;

        auto mid = begin + (end - begin) / 2;
        mergeSort(str, begin, mid);
        mergeSort(str, mid + 1, end);
        merge(str, begin, mid, end);
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, vector<string>> rMap;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs.at(i);
            string temp = str;
            mergeSort(temp, 0, temp.size() - 1);
            auto itr = rMap.find(temp);
            if (itr == rMap.end()) {
                vector<string> v;
                v.push_back(str);
                rMap.insert({temp, v});
            }
            else {
                itr->second.push_back(str);
            }
        }

        for (map<string, vector<string>>::iterator it = rMap.begin(); it != rMap.end(); ++it) {
            result.push_back(it->second);
        }
        return result;
    }
};