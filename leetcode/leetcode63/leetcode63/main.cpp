#include <iostream>
#include <vector>
using namespace std;

const int maxn = 105;

class Solution {
public:
	int dp[maxn][maxn];

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid[0][0] == 1) return 0;
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		dp[0][0] = 1;

		int flag = -1;
		for (int i = 0; i < m; ++i) {
			if (obstacleGrid[i][0]) { flag = i; break; }
			dp[i][0] = 1;
		}
		if (flag != -1) {
			for (int i = flag; i < m; ++i) dp[i][0] = 0;
		}

		flag = -1;
		for (int i = 0; i < n; ++i) {
			if (obstacleGrid[0][i]) { flag = i; break; }
			dp[0][i] = 1;
		}
		if (flag != -1) {
			for (int i = flag; i < n; ++i) dp[0][i] = 0;
		}

		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (obstacleGrid[i][j]) dp[i][j] = 0;
				else dp[i][j] = dp[i-1][j]+dp[i][j-1];
			}
		}
		return dp[m-1][n-1];
    }
};

int main()
{
	Solution sol;
	int a[][7] = {
		{0, 0, 1, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}, 
		{1, 0, 0, 0, 0, 0, 0}
	};
	vector<vector<int>> v(sizeof(a)/sizeof(a[0]), vector<int>(sizeof(a[0])/sizeof(a[0][0])));
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
		for (int j = 0; j < sizeof(a[i])/sizeof(a[i][0]); ++j) {
			v[i][j] = a[i][j];
		}
	}
	sol.uniquePathsWithObstacles(v);
	return 0;
}