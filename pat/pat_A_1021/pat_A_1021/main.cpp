#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Node {
	int vertex;
	Node *next;
}AdjList;

typedef struct {
	int index, deepest;
}Deep;

const int maxn = 1e4 + 10;
int N;
AdjList adj[maxn];
bool visit[maxn]; int cnt = 1;
vector<Deep> deep;

void dfs(int n)
{
	Node *node = adj[n].next;
	for ( ; node != NULL; node = node->next) {
		if (!visit[node->vertex]) {
			visit[node->vertex] = true; ++cnt;
			dfs(node->vertex);
		}
	}
	return;
}

int find_components()
{
	memset(visit, 0, sizeof(visit));
	int ans = 0; cnt = 0;
	for (int i = 1; i <= N; ++i) {
		if (!visit[i]) {
			dfs(i); ++ans;
		}
	}
	return ans;
}

bool cmp(const Deep &d1, const Deep &d2)
{
	if (d1.deepest != d2.deepest) return d1.deepest > d2.deepest;
	return d1.index < d2.index;
}

void find_deepest()
{
	for (int i = 1; i <= N; ++i) {
		memset(visit, 0, sizeof(visit));
		queue<int> q; int deepest = 0;
		q.push(i); visit[i] = true;
		q.push(-1); cnt = 1;
		while (!q.empty()) {
			int i = q.front(); q.pop();
			if (i == -1) { 
				q.push(-1); ++deepest;
				if (cnt == N) break;
				continue;
			}
			Node *n = adj[i].next;
			for ( ; n != NULL; n = n->next) {
				if (!visit[n->vertex]) {
					visit[n->vertex] = true;
					q.push(n->vertex);
					++cnt;
				}
			}
		}
		Deep d; d.index = i; d.deepest = deepest;
		deep.push_back(d);
	}

	sort(deep.begin(), deep.end(), cmp);
	printf("%d\n", deep[0].index);
	for (int i = 1; i < deep.size(); ++i) {
		if (deep[i].deepest == deep[0].deepest) {
			printf("%d\n", deep[i].index);
		} else break;
	}
	return;
}

void solve()
{
	cin >> N;
	for (int i = 0; i < N-1; ++i)
	{
		int u, v; scanf("%d %d", &u, &v);
		Node *node1 = (Node *)malloc(sizeof(Node));
		node1->vertex = v;
		node1->next = adj[u].next;
		adj[u].next = node1;
		adj[u].vertex = u;

		Node *node2 = (Node *)malloc(sizeof(Node));
		node2->vertex = u;
		node2->next = adj[v].next;
		adj[v].next = node2;
		adj[v].vertex = v;
	}

	visit[1] = true; dfs(1);
	if (cnt < N) printf("Error: %d components\n", find_components());
	else find_deepest();
	return;
}

int main()
{
	solve();
	return 0;
}

/*
5
2 5
4 1
1 3
1 2

9
1 2
1 3
1 4
2 9
3 5
3 7
5 6
5 8
*/