/*
4 7
a b
a b
a c
a c
a d
b d
c d
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct Node {
	int vertex;
	Node *next;
}AdjList;
const int maxn = 1010;
AdjList adj[maxn];
int n, edge, degree[maxn];
int visit[maxn];

void init()
{
	cin >> n >> edge;
	memset(adj, 0, sizeof(adj));
	for (int i = 0; i < n; i++)
	{
		adj[i].vertex = i;
		adj[i].next = NULL;
	}
	for (int e = 0; e < edge; e++)
	{
		char u, v;
		cin >> u >> v;
		Node *node1 = (Node *)malloc(sizeof(Node));
		node1->vertex = v-'a';
		node1->next = adj[u-'a'].next;
		adj[u-'a'].next = node1;

		Node *node2 = (Node *)malloc(sizeof(Node));
		node2->vertex = u-'a';
		node2->next = adj[v-'a'].next;
		adj[v-'a'].next = node2;
	}
	return;
}

void dfs(int vertex)
{
	visit[vertex] = 1;
	Node *node = adj[vertex].next;
	for ( ; node != NULL; node = node->next) 
		if (!visit[node->vertex]) dfs(node->vertex);
	return;
}

bool connected()
{
	memset(visit, 0, sizeof(visit));
	dfs(0);
	int sum = 0;
	for (int i = 0; i < n; i++) sum += visit[i];
	if (sum != n) return false;
	return true;
}

bool solve()
{
	if (!connected()) return false;
	memset(degree, 0, sizeof(degree));
	for (int i = 0; i < n; i++)
	{
		Node *node = adj[i].next;
		for ( ; node != NULL; node = node->next)
			degree[i]++;
	}

	int odd_degree = 0;
	for (int i = 0; i < n; i++)
		if (degree[i]%2) odd_degree++;
	if (odd_degree > 2) return false;
	return true;
}

int main()
{
	init();
	if (solve()) cout << "yep" << endl;
	else cout << "nope" << endl;
	return 0;
}