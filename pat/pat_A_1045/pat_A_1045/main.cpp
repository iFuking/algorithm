#include <iostream>
using namespace std;

const int maxn = 205;
bool hash_color[maxn];
int order[maxn];
const int maxl = 1e5 + 10;
int stripe[maxl], dp[maxl];

void solve()
{
	int N; cin >> N;
	int M; cin >> M;
	for (int i = 0; i < M; ++i) {
		int color; scanf("%d", &color);
		hash_color[color] = true;
		order[color] = i;
	}
	int L; cin >> L;
	for (int i = 0; i < L; ++i) scanf("%d", &stripe[i]);

	int ans = 0;
	for (int i = 0; i < L; ++i) {
		if (hash_color[stripe[i]]) {
			int max_ans = 0;
			for (int j = 0; j < i; ++j) {
				if (order[stripe[j]]<=order[stripe[i]] && dp[j]>max_ans) {
					max_ans = dp[j];
				}
			}
			dp[i] = max_ans+1;
		}
		if (dp[i] > ans) ans = dp[i];
	}
	printf("%d\n", ans);
	return;
}

int main()
{
	solve();
	return 0;
}