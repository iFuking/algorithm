#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn];
vector<char> help;

int b_search(char ch) {
	int left = 0, right = help.size()-1;
	while (left <= right) {
		int mid = (left+right) >> 1;
		if (help[mid] < ch) left = mid+1;
		else right = mid-1;
	}
	return left;
}

int longest_increasing_subsequence_length(const string &s) {
	int longest_length = 1;
	dp[0] = 1; help.push_back(s[0]);
	for (int i = 1; i < s.length(); ++i) {
		int index = b_search(s[i]);
		if (index < help.size()) help[index] = s[i];
		else help.push_back(s[i]);
		dp[i] = index+1;

		if (dp[i] > longest_length) {
			longest_length = dp[i];
		}
	}
	return longest_length;
}

string longest_increasing_subsequence(const string &s) {
	int longest_length = 0, index;
	for (int i = 0; i < s.length(); ++i) {
		if (dp[i] > longest_length) {
			longest_length = dp[index=i];
		}
	}

	string str; str += s[index];
	for (int i = s.length()-1; i >= 0; --i) {
		if (dp[i]+1 == dp[index]) {
			str += s[i]; index = i;
		}
	}
	reverse(str.begin(), str.end());
	return str;
}

void solve() {
	string s; cin >> s;
	printf("%d\n", longest_increasing_subsequence_length(s));
	printf("%s\n", longest_increasing_subsequence(s).c_str());
	return;
}

int main() {
	solve();
	return 0;
}
