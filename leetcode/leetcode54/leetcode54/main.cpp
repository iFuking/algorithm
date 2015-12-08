#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
		if (matrix.size() == 0) return ans;

		int left = 0, right = matrix[0].size()-1;
		int top = 0, bottom = matrix.size()-1;
		while (true) {
			for (int i = left; i <= right; ++i) ans.push_back(matrix[top][i]);
			++top; if (top > bottom) break;
			for (int i = top; i <= bottom; ++i) ans.push_back(matrix[i][right]);
			--right; if (right < left) break;
			for (int i = right; i >= left; --i) ans.push_back(matrix[bottom][i]);
			--bottom; if (bottom < top) break;
			for (int i = bottom; i >= top; --i) ans.push_back(matrix[i][left]);
			++left; if (left > right) break;
		}
		return ans;
    }
};

int main()
{
	Solution sol;
	int a[][1] = {
		{1}
	};
	vector<vector<int>> v(sizeof(a)/sizeof(a[0]), vector<int>(sizeof(a[0])/sizeof(a[0][0])));
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
		for (int j = 0; j < sizeof(a[i])/sizeof(a[i][0]); ++j) {
			v[i][j] = a[i][j];
		}
	}
	sol.spiralOrder(v);
}