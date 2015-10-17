#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int maxn = 1e3 + 5;
int dp[maxn][maxn];

class LongestSubstring {
public:
	int findLongest(string A, int n, string B, int m) {
		if (n==0 || m==0) return 0;

		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++i) {
			if (A[i] == B[0]) dp[i][0] = 1;
		}
		for (int j = 0; j < m; ++j) {
			if (B[j] == A[0]) dp[0][j] = 1;
		}

		int ans = -1;
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				if (A[i] == B[j]) {
						dp[i][j] = dp[i-1][j-1]+1;
						if (dp[i][j] > ans) ans = dp[i][j];
				}
			}
		}
		return ans;
	}
};

int main()
{
	LongestSubstring ls;
	cout << ls.findLongest("cbb",3,"acabaab",7) << endl;
	return 0;
}
