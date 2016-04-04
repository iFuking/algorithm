#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn][maxn];

int longest_common_substring_length(const string &s1, const string &s2) {
	for (int i = 0; i < s1.length(); ++i) {
		if (s1[i] == s2[0]) dp[i][0] = 1;
	}
	for (int j = 0; j < s2.length(); ++j) {
		if (s1[0] == s2[j]) dp[0][j] = 1;
	}

	int longest_length = 0;
	for (int i = 1; i < s1.length(); ++i) {
		for (int j = 1; j < s2.length(); ++j) {
			if (s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = 0;

			if (dp[i][j] > longest_length) {
				longest_length = dp[i][j];
			}
		}
	}
	return longest_length;
}

string longest_common_substring(const string &s1, const string &s2) {
	int longest_length = 0, index_i;
	for (int i = 0; i < s1.length(); ++i) {
		for (int j = 0; j < s2.length(); ++j) {
			if (dp[i][j] > longest_length) {
				longest_length = dp[index_i=i][j];
			}
		}
	}
	return s1.substr(index_i-longest_length+1, longest_length);
}

void solve() {
	string s1, s2; cin >> s1 >> s2;
	printf("%d\n", longest_common_substring_length(s1, s2));
	printf("%s\n", longest_common_substring(s1, s2).c_str());
	return;
}

int main() {
	solve();
	return 0;
}