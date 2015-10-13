#include <iostream>
#include <string>
using namespace std;

const int maxn = 1e3 + 10;
bool dp[maxn][maxn];

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		if (s1=="" && s2!=s3) return false;
		else if (s2=="" && s1!=s3) return false;
		else if (s1.length()+s2.length() != s3.length()) return false;

		dp[0][0] = true;
		for (int i = 1; i <= s1.length(); ++i) {
			if (s1.substr(0, i) == s3.substr(0, i)) dp[i][0] = true;
			else dp[i][0] = false;
		}
		for (int j = 1; j <= s2.length(); ++j) {
			if (s2.substr(0, j) == s3.substr(0, j)) dp[0][j] = true;
			else dp[0][j] = false;
		}

		for (int i = 1; i <= s1.length(); ++i) {
			for (int j = 1; j <= s2.length(); ++j) {
				if (dp[i-1][j] && s1[i-1]==s3[i+j-1]) dp[i][j] = true;
				else if (dp[i][j-1] && s2[j-1]==s3[i+j-1]) dp[i][j] = true;
				else dp[i][j] = false;
			}
		}
		return dp[s1.length()][s2.length()];
    }
};

int main()
{
	Solution sol;
	cout << sol.isInterleave("", "", "a") << endl;
	return 0;
}