#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <ctime>
using namespace std;

const int inf = 0x3fffffff;
const int maxn = 1010;
int N, E;
int w[maxn][maxn], d[maxn];
bool visit[maxn];
int path[maxn];

void dijkstra(int s)
{
	visit[s] = true;
	for (int i = 1; i <= N; ++i) {
		d[i] = w[s][i];
		if (d[i] < inf) path[i] = s;
	}

	int times = 0;  // iterate N-1 times
	while (times < N-1)
	{
		int shortest = inf, flag;
		for (int i = 1; i <= N; ++i) {
			if (!visit[i] && d[i]<shortest) shortest = d[flag=i];
		}
		visit[flag] = true;
		for (int i = 1; i <= N; ++i) {
			if (!visit[i] && w[flag][i]<inf) {
				if (d[flag]+w[flag][i] < d[i]) {
					d[i] = d[flag]+w[flag][i];
					path[i] =flag;
				}
			}
		}
		++times;
	}
	return;
}

void solve()
{
	cin >> N >> E;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			w[i][j] = inf;
			if (i == j) w[i][j] = 0;
		}
	}

	for (int i = 0; i < E; ++i)
	{
		int u, v, weight;
		scanf("%d %d %d", &u, &v, &weight);
		w[u][v] = weight;
		w[v][u] = weight;
	}
	dijkstra(6);
	return;
}

int main()
{
	solve();
	return 0;
}


/*
6 10
1 2 32
1 4 43
1 6 57
2 3 82
2 6 19
3 4 109
3 5 90
3 6 65
4 5 79
5 6 24
*/