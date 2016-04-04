#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn];

int longest_increasing_substring_length(const string &s) {
	for (int i = 0; i < s.length(); ++i) {
		dp[i] = 1;
	}

	int longest_length = 1;
	for (int i = 1; i < s.length(); ++i) {
		if (s[i] > s[i-1]) {
			dp[i] = dp[i-1]+1;
		}

		if (dp[i] > longest_length) {
			longest_length = dp[i];
		}
	}

	return longest_length;
}

string longest_increasing_substring(const string &s) {
	int longest_length = 0, index;
	for (int i = 0; i < s.length(); ++i) {
		if (dp[i] > longest_length) {
			longest_length = dp[index=i];
		}
	}
	return s.substr(index-longest_length+1, longest_length);
}

void solve() {
	string s; cin >> s;
	printf("%d\n", longest_increasing_substring_length(s));
	printf("%s\n", longest_increasing_substring(s).c_str());
	return;
}

int main() {
	solve();
	return 0;
}