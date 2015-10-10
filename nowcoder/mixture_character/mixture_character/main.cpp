#include <iostream>
#include <string>
using namespace std;

const int maxn = 105;
// if s1[0..i-1] and s2[0..j-1] -> aim[0..i+j-1], dp[i][j] = true;
// else dp[i][j] = false; (empty string included)
bool dp[maxn][maxn];

class Mixture {
public:
    bool chkMixture(string A, int n, string B, int m, string C, int v) {
		dp[0][0] = true;  // empty string s1 and empty string s2 contribute empty string aim
		// dp[0][j]: s2[0..j-1] -> aim[0..j-1] ?
		// dp[i][0]: s1[0..i-1] -> aim[0..i-1] ?
		for (int j = 1; j <= m; ++j) {
			if (B.substr(0, j-1) == C.substr(0, j-1)) dp[0][j] = true;
			else dp[0][j] = false;
		}
		for (int i = 1; i <= n; ++i) {
			if (A.substr(0, i-1) == C.substr(0, i-1)) dp[i][0] = true;
			else dp[i][0] = false;
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (dp[i-1][j] && A[i-1]==C[i+j-1]) dp[i][j] = true;
				else if (dp[i][j-1] && B[j-1]==C[i+j-1]) dp[i][j] = true;
				else dp[i][j] = false;
			}
		}
		return dp[n][m];
    }
};

int main()
{
	Mixture sol;
	cout << sol.chkMixture("AB", 2, "12", 2, "A1B2", 4) << endl;
	return 0;
}