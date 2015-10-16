#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int maxn = 1e4 + 10;
const int maxm = 5e4 + 10;
int N, M;
map<int, vector<int>> graph;
map<int, vector<int>> reach;
bool visit[maxn];
int popular[maxn];

void dfs(int v, int i)
{
	vector<int>::iterator iter = graph[i].begin();
	for ( ; iter != graph[i].end(); ++iter) {
		if (!visit[*iter]) {
			visit[*iter] = true;
			reach[v].push_back(*iter);
			dfs(v, *iter);
		}
	}
	return;
}

void solve()
{
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		graph[a].push_back(b);
	}

	for (int i = 1; i <= N; ++i) {
		memset(visit, 0, sizeof(visit));
		visit[i] = true; dfs(i, i);
	}

	map<int, vector<int>>::iterator iter = reach.begin();
	for ( ; iter != reach.end(); ++iter) {
		vector<int>::iterator it = iter->second.begin();
		for ( ; it != iter->second.end(); ++it) ++popular[*it];
	}

	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		if (popular[i] == N-1) ++cnt;
	}
	cout << cnt << endl;
	return;
}

int main()
{
	solve();
	return 0;
}


/*
3 3
1 2
2 1
2 3

4 4
1 2
2 3
3 4
3 1
*/