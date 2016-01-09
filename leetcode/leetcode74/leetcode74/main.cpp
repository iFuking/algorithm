#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int top = 0, bottom = matrix.size()-1;
		while (top <= bottom) {
			int median = (top+bottom) >> 1;
			if (target < matrix[median][0]) bottom = median-1;
			else if (target > matrix[median][0]) top = median+1;
			else return true;
		}
		if (bottom < 0) return false;
		int left = 0, right = matrix[bottom].size()-1;
		while (left <= right) {
			int mid = (left+right) >> 1;
			if (target < matrix[bottom][mid]) right = mid-1;
			else if (target > matrix[bottom][mid]) left = mid+1;
			else return true;
		}
		return false;
    }
};

int main()
{
	Solution sol;
	int a[][4] = {
		{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}
	};
	vector<vector<int>> v(sizeof(a)/sizeof(a[0]), vector<int>(sizeof(a[0])/sizeof(a[0][0])));
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
		for (int j = 0; j < sizeof(a[i])/sizeof(a[i][0]); ++j) {
			v[i][j] = a[i][j];
		}
	}
	sol.searchMatrix(v, 0);
	return 0;
}