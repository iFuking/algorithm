#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		vector<bool> rows(matrix.size());
		vector<bool> cols(matrix[0].size());
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[i].size(); ++j) {
				if (matrix[i][j] == 0) {
					rows[i] = true; cols[j] = true;
				}
			}
		}

		for (int i = 0; i < matrix.size(); ++i) {
			if (rows[i]) {
				for (int j = 0; j < matrix[i].size(); ++j) {
					matrix[i][j] = 0;
				}
			}
		}
		for (int j = 0; j < matrix[0].size(); ++j) {
			if (cols[j]) {
				for (int i = 0; i < matrix.size(); ++i) {
					matrix[i][j] = 0;
				}
			}
		}
		return;
    }
};

int main()
{
	Solution sol;
	int a[][4] = {
		{0, 0, 0, 5}, {4, 3, 1, 4}, {0, 1, 1, 4}, {1, 2, 1, 3}, {0, 0, 1, 1}
	};
	vector<vector<int>> v(sizeof(a)/sizeof(a[0]), vector<int>(sizeof(a[0])/sizeof(a[0][0])));
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
		for (int j = 0; j < sizeof(a[i])/sizeof(a[i][0]); ++j) {
			v[i][j] = a[i][j];
		}
	}
	sol.setZeroes(v);
	return 0;
}