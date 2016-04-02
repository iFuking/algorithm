#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int M = 1e9 + 7;
const int maxa = 1e5 + 10;
const int maxn = 1e6 + 10;
vector<int> fib;
int a[maxn];

void solve() {
	int n, max_ai = -1; cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		max_ai = max(max_ai, a[i]);
	}


	fib.push_back(1); fib.push_back(1);
	for (int i = 1; ; ++i) {
		int fib_num = fib[i]+fib[i-1];
		if (fib_num<maxa && fib_num<=max_ai) {
			fib.push_back(fib_num);
		} else break;
	}

	// for (int i = 0; i < fib.size(); ++i) {
	// 	printf("%d\n", fib[i]);
	// }
	// printf("fib size: %d\n", (int)fib.size());


	int m = fib.size();
	vector<vector<int> > dp(m+1, vector<int>(n+1));
	for (int i = 0; i <= m; ++i) {
		dp[i][0] = 0;
	}
	for (int j = 0; j <= n; ++j) {
		dp[0][j] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		int tmp_max = -1;
		for (int j = 1; j <= n; ++j) {
			dp[i][j] = dp[i][j-1];
			if (fib[i-1] == a[j-1]) {
				dp[i][j] += dp[i-1][j-1];
			}
			tmp_max = max(tmp_max, dp[i][j]);
		}
		ans = (ans+tmp_max)%M;
	}
	printf("%d\n", ans);
	return;
}

int main() {
	solve();
	return 0;
}