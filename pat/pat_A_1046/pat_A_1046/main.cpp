#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int dis[maxn];

void swap(int &n1, int &n2)
{
	int n = n1; n1 = n2; n2 = n;
	return;
}

void solve()
{
	int N; cin >> N;
	int sum = 0;
	for (int i = 1; i <= N; ++i) {
		int d; scanf("%d", &d);
		dis[i] = sum; sum += d;
	}

	int M; cin >> M;
	for (int i = 0; i < M; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		if (u > v) swap(u, v);
		int distance = dis[v]-dis[u];
		printf("%d\n", min(distance, sum-distance));
	}
	return;
}

int main()
{
	solve();
	return 0;
}