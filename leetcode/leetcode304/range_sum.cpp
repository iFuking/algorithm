#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
    vector<vector<int> > sum;

    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() > 0) {
            sum = vector<vector<int> >(matrix.size()+1, vector<int>(matrix[0].size()+1));
            for (int i = 0; i < matrix.size(); ++i) {
                for (int j = 0; j < matrix[i].size(); ++j) {
                    sum[i+1][j+1] = sum[i][j+1]+sum[i+1][j]+matrix[i][j]-sum[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        
    }
};