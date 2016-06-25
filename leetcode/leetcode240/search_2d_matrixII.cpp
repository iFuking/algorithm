#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int row = matrix.size();
        if (row == 0) return false;
        int col = matrix[0].size();

        int r = row-1, c = 0;
        while (r>=0 && c<col) {
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] < target) {
                ++c;
            } else if (matrix[r][c] > target) {
                --r;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    int a[][5] = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    vector<vector<int> > v(sizeof(a)/sizeof(a[0]), vector<int>(sizeof(a[0])/sizeof(a[0][0]), 0));
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
        for (int j = 0; j < sizeof(a[0])/sizeof(a[0][0]); ++j) {
            v[i][j] = a[i][j];
        }
    }

    cout << sol.searchMatrix(v, 20) << endl;
    return 0;
}