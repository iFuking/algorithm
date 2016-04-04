#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn][maxn];

int longest_palindrome_subsequence_length(int i, int j, const string &s) {
	if (i > j) return 0;
	if (dp[i][j]) return dp[i][j];
	if (i == j) return dp[i][j] = 1;

	if (s[i] == s[j]) {
		dp[i][j] = longest_palindrome_subsequence_length(i+1, j-1, s)+2;
	} else {
		dp[i][j-1] = longest_palindrome_subsequence_length(i, j-1, s);
		dp[i+1][j] = longest_palindrome_subsequence_length(i+1, j, s);
		dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
	}
	return dp[i][j];
}

string longest_palindrome_subsequence(const string &s) {
	string str;
	int i = 0, j = s.length()-1;
	while (i <= j) {
		if (dp[i][j] == dp[i][j-1]) --j;
		else if (dp[i][j] == dp[i+1][j]) ++i;
		else {
			str += s[i];
			++i; --j;
		}
	}

	int str_length = str.length(), longest_length = dp[0][s.length()-1];
	if (longest_length % 2 == 0) {
		str += str[str.length()-1];
	}
	for (int i = str_length-2; i >= 0; --i) {
		str += str[i];
	}
	return str;
}

void solve() {
	string s; cin >> s;
	printf("%d\n", longest_palindrome_subsequence_length(0, s.length(), s));
	printf("%s\n", longest_palindrome_subsequence(s).c_str());
	return;
}

int main() {
	solve();
	return 0;
}