/*
7 11
0 5
0 2
0 1
3 6
3 5
3 4
5 2
6 4
6 0
3 2
1 4
*/
#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

typedef struct Node {
	int id;
	Node *next;
}AdjList;
const int maxn = 1010;
AdjList adj[maxn];
bool visit[maxn];
int n, edge;
stack<int> post_order;


void init()
{
	cin >> n >> edge;
	memset(adj, 0, sizeof(adj));
	for (int i = 0; i < n; i++)
	{
		adj[i].id = i;
		adj[i].next = NULL;
	}

	// build adjacency list
	for (int e = 0; e < edge; e++)
	{
		int u, v;
		cin >> u >> v;
		Node *node = (Node *)malloc(sizeof(Node));
		node->id = v;
		node->next = adj[u].next;
		adj[u].next = node;
	}
	return;
}

void dfs(int vertex)
{
	visit[vertex] = true;
	Node *node = adj[vertex].next;
	if (node != NULL)
		for ( ; node != NULL; node = node->next)
			if (!visit[node->id]) dfs(node->id);
	post_order.push(vertex);
	return;
}

void topsort()
{
	memset(visit, 0, sizeof(visit));
	for (int u = 0; u < n; u++)
		if (!visit[u]) dfs(u);
	while (!post_order.empty()) 
	{ 
		cout << post_order.top() << " ";
		post_order.pop();
	}
	cout << endl;
	return;
}

int main()
{
	init();
	topsort();

	return 0;
}