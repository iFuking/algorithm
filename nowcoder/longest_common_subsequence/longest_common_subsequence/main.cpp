#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1e3 + 10;
char str1[maxn], str2[maxn];
int dp[maxn][maxn];    // dp[i][j]: length of longest common subsequence between str1[0..i] and str2[0..j]
vector<char> seq;

void gen_dp()
{
	bool flag = false;
	for (int j = 0; j < strlen(str2); ++j) {
		if (flag) { dp[0][j] = 1; continue; }
		if (str1[0] != str2[j]) dp[0][j] = 0;
		else { dp[0][j] = 1; flag = true; }
	}
	flag = false;
	for (int i = 0; i < strlen(str1); ++i) {
		if (flag) { dp[i][0] = 1; continue; }
		if (str1[i] != str2[0]) dp[i][0] = 0;
		else { dp[i][0] = 1; flag = true; }
	}

	for (int i = 1; i < strlen(str1); ++i) {
		for (int j = 1; j < strlen(str2); ++j) {
			if (str1[i] == str2[j]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return;
}

void find_seq()
{
	int i = strlen(str1)-1;
	int j = strlen(str2)-1;
	while (i>=0 && j>=0 && seq.size()<dp[strlen(str1)-1][strlen(str2)-1]) {
		if (dp[i][j] == dp[i-1][j]) --i;
		else if (dp[i][j] == dp[i][j-1]) --j;
		else { seq.push_back(str1[i]); --i; --j; }
	}

	for (int i = seq.size()-1; i >= 0; --i) printf("%c", seq[i]);
	cout << endl;
	return;
}

void solve()
{
	scanf("%s %s", str1, str2);
	gen_dp();
	find_seq();
	return;
}

int main()
{
	solve();
	return 0;
}

/*
1A2C3D4B56 B1D23CA45B6A
*/