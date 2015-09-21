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

typedef struct {
	int either, other;
	int weight;
}Edge;
const int inf = 0x3fffffff;
const int maxn = 1010;
int N, E;
int w[maxn][maxn];
bool mark[maxn];
priority_queue<Edge> pq;

bool operator <(const Edge &e1, const Edge &e2) { return e1.weight > e2.weight; }

void visit(int vertex)
{
	mark[vertex] = true;
	for (int i = 1; i <= N; ++i)
	{
		if (!mark[i] && w[vertex][i]<inf)
		{
			Edge e;
			e.either = vertex; e.other = i;
			e.weight = w[vertex][i];
			pq.push(e);
		}
	}
	return;
}

int prim()
{
	int ans = 0;
	vector<Edge> mst;
	visit(1);
	while (!pq.empty() && mst.size()<N-1)
	{
		Edge e = pq.top(); pq.pop();
		int u = e.either, v = e.other;
		if (mark[u] && mark[v]) continue;
		mst.push_back(e);
		ans += e.weight;
		if (!mark[u]) visit(u);
		if (!mark[v]) visit(v);
	}
	return ans;
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

	printf("%d\n", prim());
	return;
}

int main()
{
	solve();
	return 0;
}


/*
7 11
1 2 7
1 4 5
2 3 8
2 4 9
2 5 7
3 5 5
4 5 15
4 6 6
5 6 8
5 7 9
6 7 11
*/