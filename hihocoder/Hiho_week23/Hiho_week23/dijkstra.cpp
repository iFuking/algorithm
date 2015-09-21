#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1010
#define INF 1010
#define INT_MAX 0x7fffffff
using namespace std;

int V, E, s, t;
int weight[MAXN][MAXN];
int dist[MAXN], marked[MAXN];

int Min(int a, int b)
{
	return a < b ? a : b;
}

void Predo()
{
	cin >> V >> E >> s >> t;
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
			weight[i][j] = INF;
		if (i != s)
			dist[i] = INT_MAX;
	}

	for (int i = 0; i < E; i++)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		if (w < weight[v1][v2])
		{
			weight[v1][v2] = w;
			weight[v2][v1] = w;
		}
	}
	return;
}

void Dijkstra()
{
	for (int i = 0; i < V; i++)
	{
		int min = INT_MAX, flag = -1;
		for (int j = 1; j <= V; j++)
		{
			if (!marked[j] && dist[j]<min)
				min = dist[flag=j];
		}
		marked[flag] = 1;
		for (int j = 1; j <= V; j++)
			if (weight[flag][j] != INF)
				dist[j] = Min(dist[j], dist[flag]+weight[flag][j]);
	}
	return;
}

int main(int argc, char *argv[])
{
	Predo();
	Dijkstra();
	cout << dist[t] << endl;

	system("pause");
	return 0;
}