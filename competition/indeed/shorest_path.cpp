#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e2 + 10;
int N, Q;
int w[maxn][maxn], d[maxn];
bool visit[maxn];

int dijkstra(int s, int e)
{
	memset(visit, 0, sizeof(visit));
	visit[s] = true;
	for (int i = 1; i <= N; ++i) {
		d[i] = w[s][i];
	}

	// iterate N-1 times
	for (int t = 0; t < N-1; ++t)
	{
		int shortest = INF, flag=-1;
		for (int i = 1; i <= N; ++i) {
			if (!visit[i] && d[i]<shortest) {
				shortest = d[flag=i];
			}
		}
		if (flag == -1) continue;

		visit[flag] = true;
		for (int i = 1; i <= N; ++i) {
			if (!visit[i] && w[flag][i]<INF) {
				d[i] = min(d[i], d[flag]+w[flag][i]);
			}
		}
	}
	return d[e]==INF ? -1 : d[e];
}

void solve()
{
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i != j) {
				w[i][j] = INF;
			}
		}
	}
	for (int i = 1; i < N; ++i) {
		w[i][i+1] = 1;
	}

	int s, e;
	for (int q = 0; q < Q; ++q) {
		scanf("%d %d", &s, &e);
		printf("%d\n", dijkstra(s, e));
		w[s][e] = 1;
	}
	return;
}

int main()
{
	solve();
	return 0;
}