#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn][maxn];

int longest_common_subsequence_length(const string &s1, const string &s2) {
	int index_i = -1;
	for (int i = 0; i < s1.length(); ++i) {
		if (s1[i] != s2[0]) dp[i][0] = 0;
		else { index_i = i; break; }
	}
	if (index_i > -1) {
		for (int i = index_i; i < s1.length(); ++i) {
			dp[i][0] = 1;
		}
	}

	int index_j = -1;
	for (int j = 0; j < s2.length(); ++j) {
		if (s1[0] != s2[j]) dp[0][j] = 0;
		else { index_j = j; break; }
	}
	if (index_j > -1) {
		for (int j = index_j; j < s2.length(); ++j) {
			dp[0][j] = 1;
		}
	}


	for (int i = 1; i < s1.length(); ++i) {
		for (int j = 1; j < s2.length(); ++j) {
			if (s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	return dp[s1.length()-1][s2.length()-1];
}

string longest_common_subsequence(const string &s1, const string &s2) {
	int i = s1.length()-1, j = s2.length()-1;
	string s;
	while (i>=0 && j>=0 && s.length()<dp[s1.length()-1][s2.length()-1]) {
		if (dp[i][j] == dp[i][j-1]) --j;
		else if (dp[i][j] == dp[i-1][j]) --i;
		else {
			s += s1[i];
			--i; --j;
		}
	}
	reverse(s.begin(), s.end());
	return s;
}

void solve() {
	string s1, s2; cin >> s1 >> s2;
	printf("%d\n", longest_common_subsequence_length(s1, s2));
	printf("%s\n", longest_common_subsequence(s1, s2).c_str());
	return;
}

int main() {
	solve();
	return 0;
}
