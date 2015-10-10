#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <cstring>
using namespace std;

typedef struct Node{
	int data;
	Node *next;
}List;
const int maxn = 1010;
int N, L;
List list[maxn];
bool visit[maxn];

void solve()
{
	cin >> N >> L;
	for (int i = 1; i <= N; ++i)
	{
		list[i].data = i;
		list[i].next = NULL;
	}
	for (int i = 1; i <= N; ++i)
	{
		int M; scanf("%d", &M);
		for (int j = 0; j < M; ++j)
		{
			int id; scanf("%d", &id);
			Node *p = (Node *)malloc(sizeof(Node));
			p->data = i;
			p->next = list[id].next;
			list[id].next = p;
		}
	}

	int K; cin >> K;
	for (int i = 0; i < K; ++i)
	{
		int id; scanf("%d", &id);
		memset(visit, 0, sizeof(visit));
		queue<int> q; q.push(id); visit[id] = true;
		q.push(-1);  // separate different levels
		int level = 0;
		while (!q.empty())
		{
			if (level == L) break;
			int u_id = q.front(); q.pop();
			if (u_id == -1) { q.push(-1); ++level; continue; }
			for (Node *p = list[u_id].next; p != NULL; p = p->next) {
				if (!visit[p->data]) {
					q.push(p->data); visit[p->data] = true;
				}
			}
		}
		visit[id] = false; int cnt = 0;
		for (int i = 1; i <= N; ++i) {
			if (visit[i]) ++cnt;
		}
		printf("%d\n", cnt);
	}
	return;
}

int main()
{
	solve();
	return 0;
}


/*
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
*/