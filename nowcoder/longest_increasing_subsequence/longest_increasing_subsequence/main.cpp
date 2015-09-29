#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int maxn = 1e3 + 10;
int N, arr[maxn];  // array
int dp[maxn];      // dp[i]: length of arr[0..i]'s longest increasing subsequence
vector<int> help;  // help to calculate dp[i]
vector<int> seq;   // such subsequence matches the meets

int b_search(int n)
{
	int left = 0, right = help.size()-1;
	while (left <= right)
	{
		int mid = (left+right) >> 1;
		if (n <= help[mid]) right = mid-1;
		else left = mid+1;
	}
	return left;
}

void gen_dp()
{
	dp[0] = 1;
	help.push_back(arr[0]);

	for (int i = 1; i < N; ++i)
	{
		int index = b_search(arr[i]);
		if (index < help.size()) help[index] = arr[i];
		else help.push_back(arr[i]);
		dp[i] = index+1;
	}
	return;
}

void find_seq()
{
	int max_dp = -1, flag;
	for (int i = 0; i < N; ++i) {
		if (dp[i] > max_dp) max_dp = dp[flag=i];
	}
	seq.push_back(arr[flag]);
	
	int cur = flag;
	for (int i = flag; i>=0 && seq.size()<max_dp; --i) {
		if (arr[i]<arr[cur] && dp[i]+1==dp[cur]) {
			seq.push_back(arr[i]);
			cur = i;
		}
	}

	for (int i = seq.size()-1; i >= 0; --i) printf("%d ", seq[i]);
	cout << endl;
	return;
}

void solve()
{
	cin >> N;
	for (int i = 0; i < N; ++i) scanf("%d", &arr[i]);
	
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
9
2 1 5 3 6 4 8 9 7
*/