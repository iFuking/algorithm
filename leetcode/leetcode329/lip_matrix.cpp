#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int dir[][2] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

class Solution {
public:
    int dfs(int r, int c, vector<vector<int> > &matrix, vector<vector<int> > &dp) {
        if (dp[r][c]) return dp[r][c];
        for (int i = 0; i < sizeof(dir)/sizeof(dir[0]); ++i) {
            int dr = r+dir[i][0], dc = c+dir[i][1];
            if (dr>=0 && dr<matrix.size() && dc>=0 && dc<matrix[r].size() && matrix[dr][dc]>matrix[r][c]) {
                dp[r][c] = max(dp[r][c], dfs(dr, dc, matrix, dp));
            }
        }
        return ++dp[r][c];
    }

    int longestIncreasingPath(vector<vector<int> >& matrix) {
        if (matrix.size() == 0) return 0;
        vector<vector<int> > dp(matrix.size(), vector<int>(matrix[0].size(), 0));

        int longest_incr_path = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                dp[i][j] = max(dp[i][j], dfs(i, j, matrix, dp));
                longest_incr_path = max(longest_incr_path, dp[i][j]);
            }
        }
        return longest_incr_path;
    }
};

int main()
{
    int a[1][3] = {
        {3, 4, 5}
    };
    vector<vector<int> > v(sizeof(a)/sizeof(a[0]), vector<int>(sizeof(a[0])/sizeof(a[0][0])));
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
        for (int j = 0; j < sizeof(a[0])/sizeof(a[0][0]); ++j) {
            v[i][j] = a[i][j];
        }
    }

    Solution sol;
    cout << sol.longestIncreasingPath(v) << endl;
    return 0;
}
