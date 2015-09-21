#include <iostream>
#include <set>
using namespace std;

const int maxn = 55;
int N, K;
set<int> sets[maxn];

void solve()
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int M; scanf("%d", &M);
		for (int j = 0; j < M; ++j) {
			int number; scanf("%d", &number);
			sets[i].insert(number);
		}
	}

	cin >> K;
	for (int i = 0; i < K; ++i) {
		int s1, s2; scanf("%d %d", &s1, &s2);
		--s1; --s2;
		int cnt = 0;
		set<int>::iterator iter = sets[s1].begin();
		for ( ; iter != sets[s1].end(); ++iter) {
			if (sets[s2].find(*iter) != sets[s2].end()) ++cnt;
		}
		printf("%.1f%%\n", cnt*100.0/(sets[s1].size()+sets[s2].size()-cnt));
	}
	return;
}

int main()
{
	solve();
	return 0;
}