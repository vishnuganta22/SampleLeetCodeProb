#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// Rotate Image
/// </summary>
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int start = 0;
        int end = n - 1;
        do {
            for (int i = start; i < end; i++) {
                int row = start;
                int col = i;
                int prev = matrix.at(row).at(col);
                for (int j = 0; j < 4; j++) {
                    //cout<<"actual "<<row<<" :: "<<col<<endl;
                    int prevCol = col;
                    col = n - row - 1;
                    row = prevCol;
                    //cout<<"rotated "<<row<<" :: "<<col<<endl;
                    int t = matrix.at(row).at(col);
                    matrix[row][col] = prev;
                    prev = t;
                }
            }
            start++;
            end--;
        } while (start < end);
    }
};