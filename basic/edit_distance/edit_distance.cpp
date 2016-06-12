#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int> > dp;

int edit_distance(const string &s1, const string &s2) {
	int m = s1.length(), n = s2.length();
	dp = vector<vector<int> >(m+1, vector<int>(n+1, 0));
	// vector<vector<int> > dp(m, vector<int>(n, 0));
	for (int i = 0; i <= s1.length(); ++i) {
		dp[i][0] = i;
	}
	for (int j = 0; j <= s2.length(); ++j) {
		dp[0][j] = j;
	}

	for (int i = 1; i <= s1.length(); ++i) {
		for (int j = 1; j <= s2.length(); ++j) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
			}
		}
	}
	return dp[m][n];
}

vector<string> transition_path(const string &s1, const string &s2) {
	int m = s1.length(), n = s2.length();
	int i = m, j = n;

	vector<string> path;
	path.push_back(s1);

	while (i>0 && j>0 && dp[i][j]>0) {
		if (s1[i-1] == s2[j-1]) {
			--i; --j;
			continue;
		}

		string s, ss = path.back();
		if (dp[i-1][j-1]+1 == dp[i][j]) {
			s = ss.substr(0, i-1)+s2[j-1]+ss.substr(i);
			path.push_back(s);
			--i; --j;
		} else if (dp[i][j-1]+1 == dp[i][j]) {
			s = ss.substr(0, i-1)+s2[j-1]+ss.substr(i-1);
			path.push_back(s);
			--j;
		} else if (dp[i-1][j]+1 == dp[i][j]) {
			s = ss.substr(0, i-1)+ss.substr(i);
			path.push_back(s);
			--i;
		}
	}

	int k = 1; string ss = path.back();
	while (i>0 && dp[i][j]>0) {
		path.push_back(ss.substr(k));
		++k; --i;
	}
	while (j>0 && dp[i][j]>0) {
		path.push_back(s2.substr(j-1));
		--j;
	}

	// path.push_back(s2);
	return path;
}

void solve() {
	string s1, s2; cin >> s1 >> s2;
	cout << edit_distance(s1, s2) << endl;

	vector<string> v = transition_path(s1, s2);
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
	}
	cout << endl;
	return;
}

int main() {
	solve();
	return 0;
}