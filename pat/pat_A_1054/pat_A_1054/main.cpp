#include <iostream>
#include <map>
using namespace std;

void solve()
{
	int M, N; cin >> M >> N;
	map<int, int> cnt;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int color; scanf("%d", &color);
			++cnt[color];
		}
	}

	map<int, int>::iterator iter = cnt.begin();
	int dominant = -1, flag;
	for ( ; iter != cnt.end(); ++iter) {
		if (iter->second > dominant) {
			dominant = iter->second;
			flag = iter->first;
		}
	}
	printf("%d\n", flag);
	return;
}

int main()
{
	solve();
	return 0;
}