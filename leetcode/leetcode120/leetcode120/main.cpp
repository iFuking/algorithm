#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
		vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size()-1].size()));
		dp[0][0] = triangle[0][0];
		for (int i = 1; i < triangle.size(); ++i) {
			dp[i][0] = dp[i-1][0]+triangle[i][0];
			dp[i][triangle[i].size()-1] = dp[i-1][triangle[i-1].size()-1]+triangle[i][triangle[i].size()-1];
		}
		
		for (int i = 1; i < triangle.size(); ++i) {
			for (int j = 1; j < triangle[i].size()-1; ++j) {
				dp[i][j] = min(dp[i-1][j], dp[i-1][j-1])+triangle[i][j];
			}
		}
		int ans = 0x3f3f3f3f;
		for (int i = 0; i < triangle[triangle.size()-1].size(); ++i) {
			if (dp[triangle.size()-1][i] < ans) {
				ans = dp[triangle.size()-1][i];
			}
		}
		return ans;
    }
};

int main()
{
	Solution sol;
	int a[4][4] = {
		{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}
	};
	vector<vector<int>> vv;
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
		vector<int> v;
		for (int j = 0; j <= i; ++j) {
			v.push_back(a[i][j]);
		}
		vv.push_back(v);
	}
	sol.minimumTotal(vv);
	return 0;
}