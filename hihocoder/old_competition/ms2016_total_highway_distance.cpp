#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

int N, M;

void dfs(const int &u, vector<int> &visit, map<int, vector<int> > &adj, int &cnt) {
	visit[u] = true;
	vector<int>::const_iterator iter = adj[u].begin();
	for ( ; iter != adj[u].end(); ++iter) {
		if (!visit[*iter]) {
			dfs(*iter, visit, adj, ++cnt);
		}
	}
	return;
}

long long query(map<pair<int, int>, int> &edge, map<int, vector<int> > &adj) {
	long long thd = 0LL;
	map<pair<int, int>, int>::const_iterator iter = edge.begin();
	for ( ; iter != edge.end(); ++iter) {
		vector<int> visit(N, false);
		int u = iter->first.first, v = iter->first.second, cnt = 1;
		visit[v] = true;
		dfs(u, visit, adj, cnt);
		thd += cnt*(N-cnt)*iter->second;
	}
	return thd;
}

void edit(map<pair<int, int>, int> &edge) {
	int u, v, w; scanf("%d %d %d", &u, &v, &w);
	edge[make_pair(u, v)] = w;
	return;
}

void solve() {
	cin >> N >> M;
	map<pair<int, int>, int> edge;
	map<int, vector<int> > adj;
	for (int i = 0; i < N-1; ++i) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		edge[make_pair(u, v)] = w;
		adj[u].push_back(v); adj[v].push_back(u);
	}

	for (int i = 0; i < M; ++i) {
		char cmd[10]; scanf("%s", cmd);
		if (strcmp(cmd, "QUERY") == 0) {
			printf("%lld\n", query(edge, adj));
		} else {
			edit(edge);
		}
	}
	
	return;
}

int main() {
	solve();
	return 0;
}