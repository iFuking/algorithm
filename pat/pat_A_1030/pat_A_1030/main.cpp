#include <iostream>
#include <vector>
using namespace std;

const int maxn = 505;
const int inf = 0x3f3f3f3f;
int N, M, S, D;
int weight[maxn][maxn], cost[maxn][maxn];
int dis[maxn], cst[maxn], path[maxn];
bool visit[maxn];

void dijkstra(int s)
{
	visit[s] = true;
	for (int i = 0; i < N; ++i) {
		dis[i] = weight[s][i]; cst[i] = cost[s][i];
		if (dis[i] < inf) path[i] = s;
	}

	for (int times = 0; times < N-1; ++times) {
		int min_w = inf, min_c = inf, flag;
		for (int i = 0; i < N; ++i) {
			if (!visit[i] && dis[i]<min_w) min_w = dis[flag=i];
		}
		visit[flag] = true;
		for (int i = 0; i < N; ++i) {
			if (!visit[i] && (dis[flag]+weight[flag][i]<dis[i] || 
					(dis[flag]+weight[flag][i]==dis[i]&&cst[flag]+cost[flag][i]<cst[i]))) {
				dis[i] = dis[flag]+weight[flag][i];
				cst[i] = cst[flag]+cost[flag][i];
				path[i] = flag;
			}
		}
	}
	return;
}

void print_res()
{
	vector<int> p;
	for (int i = D; i != S; i = path[i]) p.push_back(i);
	p.push_back(S);
	for (int i = p.size()-1; i >= 0; --i) printf("%d ", p[i]);
	printf("%d %d\n", dis[D], cst[D]);
	return;
}

void solve()
{
	cin >> N >> M >> S >> D;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			weight[i][j] = inf; cost[i][j] = inf;
			if (i == j) {
				weight[i][j] = 0; cost[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < M; ++i) {
		int u, v, w, c;
		scanf("%d %d %d %d", &u, &v, &w, &c);
		weight[u][v] = w; weight[v][u] = w;
		cost[u][v] = c; cost[v][u] = c;
	}

	dijkstra(S);
	print_res();
	return;
}

int main()
{
	solve();
	return 0;
}

/*
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
*/