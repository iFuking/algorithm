#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int max_mn = 310;
const int maxl = 510;
int m, n, l;
double row[max_mn/2], col[max_mn/2];
double flow[max_mn][max_mn];
int pos[maxl][2];

void init()
{
	// read input
	cin >> m >> n >> l;
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(pos, 0, sizeof(pos));
	for (int i = 0; i < m; ++i) scanf("%lf", &row[i]);
	for (int i = 0; i < n; ++i) scanf("%lf", &col[i]);
	for (int i = 0; i < l; ++i) scanf("%d %d", &pos[i][0], &pos[i][1]);

	// build graph flow
	memset(flow, 0, sizeof(flow));
	for (int i = 1; i <= m; ++i) flow[0][i] = log(row[i-1]);
	for (int i = m+1; i <= m+n; ++i) flow[i][m+n+1] = log(col[i-m-1]);
	for (int i = 0; i < l; ++i) flow[pos[i][0]][pos[i][1]+m] = 1.0*INT_MAX;
	return;
}

bool bfs(double g[max_mn][max_mn], int s, int t, int route[])
{
	bool visit[max_mn/2];
	memset(visit, 0, sizeof(visit));
	queue<int> q; 
	q.push(s); visit[s] = true;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int v = 0; v <= m+n+1; ++v)
		{
			if (!visit[v] && g[u][v]>0)
			{
				q.push(v);
				route[v] = u;
				visit[v] = true;
			}
		}
	}
	return visit[t];
}

double fordfulkerson(double graph[max_mn][max_mn], int s, int t)
{
	double g[max_mn][max_mn];
	memset(g, 0, sizeof(g));
	for (int u = 0; u <= m+n+1; ++u)
		for (int v = 0; v <= m+n+1; ++v)
			g[u][v] = graph[u][v];
	int route[max_mn/2];
	double max_flow = 0;
	while (bfs(g, s, t, route))
	{
		double path_flow = 1.0*INT_MAX;
		for (int v = t; v != s; v = route[v])
		{
			int u = route[v];
			path_flow = min(path_flow, g[u][v]);
		}

		for (int v = t; v != s; v = route[v])
		{
			int u = route[v];
			g[u][v] -= path_flow;
			g[v][u] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}

int main(int argc, char *argv[])
{
	int T; cin >> T;
	while (T--)
	{
		init();
		printf("%.4f\n", exp(fordfulkerson(flow, 0, m+n+1)));
	}
	return 0;
}