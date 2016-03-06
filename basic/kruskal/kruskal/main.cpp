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
int father[maxn];
vector<Edge> edge;

bool cmp(const Edge &e1, const Edge &e2) { return e1.weight < e2.weight; }
int find_father(int x) { return x==father[x] ? x : father[x]=find_father(father[x]); }

void kruskal()
{
	for (int i = 1; i <= N; ++i) father[i] = i;
	sort(edge.begin(), edge.end(), cmp);
	vector<Edge> mst;
	for (int i = 0; i<edge.size() && mst.size()<N-1; ++i)
	{
		int fx = find_father(edge[i].either);
		int fy = find_father(edge[i].other);
		if (fx != fy)
		{
			father[fx] = fy;
			mst.push_back(edge[i]);
		}
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
		Edge e = {u, v, weight};
		edge.push_back(e);
	}

	kruskal();
	return;
}

int main()
{
	solve();
	return 0;
}


/*
9 14
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 6 4
3 9 2
4 5 9
4 6 14
5 6 10
6 7 2
7 8 1
7 9 6
8 9 7
*/