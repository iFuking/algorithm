#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

const int max_line = 81;
const int maxn = 1e3 + 10;
vector<pair<int, string> > files;

bool cmp(const int &p1, const int &p2) {
	return files[p1].second < files[p2].second;
}
bool cmp1(const pair<int, string> &p1, const pair<int, string> &p2) {
	return p1.second < p2.second;
}

void dfs_cycle(map<int, vector<int> > &graph, vector<int> &visit, int vertex, bool &has_cycle) {
	if (visit[vertex] == 1) {
		has_cycle = true; return;
	}
	visit[vertex] = 1;
	vector<int>::iterator iter = graph[vertex].begin();
	for ( ; iter != graph[vertex].end(); ++iter) {
		if (has_cycle) break;
		if (visit[*iter] < 2) {
			dfs_cycle(graph, visit, *iter, has_cycle);
		}
	}
	visit[vertex] = 2;
	return;
}

bool has_depencency_cycle(int n, map<int, vector<int> > &graph) {
	vector<int> visit(n, 0);
	bool has_cycle = false;
	map<int, vector<int> >::iterator iter = graph.begin();
	for ( ; iter != graph.end(); ++iter) {
		if (has_cycle) return true;
		if (!visit[iter->first]) {
			dfs_cycle(graph, visit, iter->first, has_cycle);
		}
	}
	return false;
}

void dfs_order(map<int, vector<int> > &graph, vector<int> &order, vector<bool> &visit, int i) {
	visit[i] = true;
	vector<int>::iterator iter = graph[i].begin();
	for ( ; iter != graph[i].end(); ++iter) {
		if (!visit[*iter]) {
			dfs_order(graph, order, visit, *iter);
		}
	}
	order.push_back(i);
	return;
}

void solve() {
	int T; cin >> T;
	while (T--) {
		int N; scanf("%d", &N);

		char f[maxn][max_line];
		map<int, vector<int> > graph;
		files = vector<pair<int, string> >();

		for (int i = 0; i < N; ++i) {
			scanf("%s", f[i]);
			files.push_back(make_pair(i, f[i]));

			int m; scanf("%d", &m);
			for (int j = 0; j < m; ++j) {
				int k; scanf("%d", &k);
				graph[i].push_back(k);
			}

			sort(graph[i].begin(), graph[i].end(), cmp);
		}


		if (has_depencency_cycle(N, graph)) {
			printf("ERROR\n\n");
			continue;
		}

		sort(files.begin(), files.end(), cmp1);

		vector<bool> visit(N, false);
		vector<int> order;
		for (int i = 0; i < files.size(); ++i) {
			if (!visit[files[i].first]) {
				dfs_order(graph, order, visit, files[i].first);
			}
		}


		for (int i = 0; i < order.size(); ++i) {
			printf("%s\n", f[order[i]]);
		}
		printf("\n");
	}
	return;
}

int main() {
	solve();
	return 0;
}
