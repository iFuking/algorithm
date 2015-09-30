#include <iostream>
#include <string>
using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn][maxn];

class Solution {
public:
    int minDistance(string word1, string word2) {
		for (int j = 0; j <= word2.length(); ++j) dp[0][j] = j;
		for (int i = 0; i <= word1.length(); ++i) dp[i][0] = i;

		for (int i = 1; i <= word1.length(); ++i) {
			for (int j = 1; j <= word2.length(); ++j) {
				if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
				else dp[i][j] = min(min(dp[i][j-1]+1, dp[i-1][j]+1), dp[i-1][j-1]+1);
			}
		}
		return dp[word1.length()][word2.length()];
    }
};

int main()
{
	Solution sol;
	cout << sol.minDistance("", "a") << endl;
	return 0;
}