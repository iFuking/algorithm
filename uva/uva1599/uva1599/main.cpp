/*
4 6
1 2 1
1 3 2
3 4 3
2 3 1
2 4 4
3 1 1
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

typedef struct Node {
	int vertex;
	int color;
	Node *next;
}Node;
typedef struct {
	int vertex;
	Node *list;
}AdjList;
const int maxn = 100010, maxm = 200010;
AdjList adj[maxn];
int n, m;
int d[maxn];  // distance from end point, which is n
int min_clr[maxn];
bool visit[maxn];

void init()
{
	cin >> n >> m;
	memset(adj, 0, sizeof(adj));
	for (int i = 1; i <= n; i++)
	{
		adj[i].vertex = i;
		adj[i].list = NULL;
	}

	// attention! undirected graph, build adjacency list
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;

		Node *node, *node1;
		node = (Node *)malloc(sizeof(Node));
		node->vertex = v; node->color = c;
		node->next = adj[u].list;
		adj[u].list = node;

		node1 = (Node *)malloc(sizeof(Node));
		node1->vertex = u; node1->color = c;
		node1->next = adj[v].list;
		adj[v].list = node1;
	}
	return;
}

// calculate distance from n, using bfs
void bfs_from_n()
{
	memset(visit, 0, sizeof(visit));
	queue<int> q;
	d[n] = 0;
	q.push(n);
	visit[n] = true;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		Node *node = adj[u].list;
		for ( ; node != NULL; node = node->next)
		{
			if (!visit[node->vertex])
			{
				d[node->vertex] = d[u]+1;
				q.push(node->vertex);
				visit[node->vertex] = true;
			}
		}
	}
	cout << d[1] << endl;
	return;
}

void bfs_from_1()
{
	memset(visit, 0, sizeof(visit));
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		Node *node = adj[u].list;
		int min_color = 0x7fffffff;
		// find min color
		for ( ; node != NULL; node=node->next)
			if (d[node->vertex]+1==d[u] && node->color<min_color) 
				min_color = node->color;
		// save the min color, with the same d[i]
		if (!min_clr[d[u]] || min_color<min_clr[d[u]]) min_clr[d[u]] = min_color;
		else continue;  // ignore color unsatisfied
		for (node = adj[u].list ; node != NULL; node=node->next)
		{
			if (!visit[node->vertex] && d[node->vertex]+1==d[u] && node->color==min_color)
			{
				q.push(node->vertex);
				visit[node->vertex] = true;
			}
		}
	}
	return;
}

int main()
{
	init();
	bfs_from_n();
	bfs_from_1();
	for (int i = d[1]; i >= 1; i--) cout << min_clr[i] << " ";
	cout << endl;
	return 0;
}