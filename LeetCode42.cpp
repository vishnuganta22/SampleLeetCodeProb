#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// 42. Trapping Rain Water
/// </summary>
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int size = height.size();
        int* arr = new int[size];

        arr[size - 1] = 0;
        for (int i = size - 2; i > -1; i--) {
            if (height.at(i + 1) > arr[i + 1]) {
                arr[i] = height.at(i + 1);
            }
            else {
                arr[i] = arr[i + 1];
            }
        }

        int prev = 0;
        for (int i = 0; i < size; i++) {
            //cout<<"height :: " <<height.at(i)<<" prev :: " <<prev<<" next :: " << arr[i]<<endl;
            if (prev != 0 && arr[i] != 0 && prev > height.at(i) && arr[i] > height.at(i)) {
                int min;
                if (arr[i] < prev) {
                    min = arr[i];
                }
                else {
                    min = prev;
                }
                //cout<<"Water Trapped at " << i << " is "<< (min - height.at(i)) <<endl;
                result += (min - height.at(i));
            }
            else {
                //cout<<"Water Trapped at " << i << " is 0 "<<endl;
            }

            if (height.at(i) > prev) {
                prev = height.at(i);
            }
        }

        return result;
    }
};