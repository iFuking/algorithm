#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXV 100010
#define MAXDIS 1000000010
using namespace std;

typedef struct Node 
{
	int vertex;
	int weight;
	Node *next;
}List;

typedef struct 
{
	int vt;
	List *list;
}AdjList;

AdjList adj[MAXV];
bool visit[MAXV];
int dis[MAXV];

void init(int u, int v, int w)
{
	List *p = adj[u].list;
	while (p != NULL)
	{
		if (p->vertex == v)
		{
			if (p->weight > w) p->weight = w;
			goto foo;
		}
		p = p->next;
	}
	
	p = (List *)malloc(sizeof(List));
	p->vertex = v;
	p->weight = w;
	p->next = adj[u].list;
	adj[u].list = p;

foo:
	List *q = adj[v].list;
	while (q != NULL)
	{
		if (q->vertex == u)
		{
			if (q->weight > p->weight)
				q->weight = p->weight;
			return;
		}
		q = q->next;
	}

	q = (List *)malloc(sizeof(List));
	q->vertex = u;
	q->weight = p->weight;
	q->next = adj[v].list;
	adj[v].list = q;
	return;
}

int main()
{
	int V, E, s, t;
	cin >> V >> E >> s >> t;

	memset(adj, 0, sizeof(adj));
	for (int e = 0; e < E; e++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		init(u, v, w);
	}

	for (int i = 1; i <= V; i++)
		dis[i] = MAXDIS;

	queue<int> q;
	q.push(s);
	visit[s] = true;
	dis[s] = 0;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		visit[v] = false;
		
		List *p = adj[v].list;
		while (p != NULL)
		{
			int w = p->vertex;
			if (dis[v]+p->weight < dis[w])
			{
				dis[w] = dis[v]+p->weight;
				if (!visit[w])
				{
					q.push(w);
					visit[w] = true;
				}
			}
			p = p->next;
		}
	}

	cout << dis[t] << endl;

	//system("pause");
	return 0;
}