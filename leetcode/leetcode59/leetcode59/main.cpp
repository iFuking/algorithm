#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
		int left = 0, right = n-1, top = 0, bottom = n-1;
		for (int i = 1; ; ) {
			for (int j = left; j <= right; ++j) mat[top][j] = i++;
			++top; if (i>n*n || top>bottom) break;
			for (int j = top; j <= bottom; ++j) mat[j][right] = i++;
			--right; if (i>n*n || right<left) break;
			for (int j = right; j >= left; --j) mat[bottom][j] = i++;
			--bottom; if (i>n*n || bottom<top) break;
			for (int j = bottom; j >= top; --j) mat[j][left] = i++;
			++left; if (i>n*n || left>right) break;
		}
		return mat;
    }
};

int main()
{
	Solution sol;
	sol.generateMatrix(10);
	return 0;
}