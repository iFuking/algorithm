#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	vector<int> path;
	int cost;
	int teams;
}Path;

const int maxn = 510;
int N, M;
int start_c, end_c;
int teams[maxn];
int cost[maxn][maxn];
bool visit[maxn];
vector<int> path;
vector<vector<int>> paths;
vector<Path> records;

void dfs(int city)
{
	if (city == end_c) { paths.push_back(path); return; }
	for (int i = 0; i < N; ++i)
	{
		if (!visit[i] && cost[city][i]>0)
		{
			visit[i] = true;
			path.push_back(i);
			dfs(i);
			visit[i] = false;
			path.pop_back();
		}
	}
	return;
}

bool cmp(Path p1, Path p2)
{
	if (p1.cost != p2.cost) return p1.cost < p2.cost;
	return p1.teams > p2.teams;
}

void solve()
{
	cin >> N >> M >> start_c >> end_c;
	for (int i = 0; i < N; ++i) scanf("%d", &teams[i]);
	for (int i = 0; i < M; ++i)
	{
		int c1, c2, c; scanf("%d %d %d", &c1, &c2, &c);
		cost[c1][c2] = cost[c2][c1] = c;
	}
	if (start_c == end_c) { printf("1 %d\n", teams[start_c]); return; }

	visit[start_c] = true;
	path.push_back(start_c);
	dfs(start_c);
	
	for (int i = 0; i < paths.size(); ++i)
	{
		path = paths[i];
		Path r; r.path = path;
		r.cost = 0; r.teams = 0;
		for (int j = 1; j < path.size(); ++j) r.cost += cost[path[j]][path[j-1]];
		for (int j = 0; j < path.size(); ++j) r.teams += teams[path[j]];
		records.push_back(r);
	}
	sort(records.begin(), records.end(), cmp);
	int costs = records[0].cost;
	int cnt = 0;
	for (int i = 0; i < records.size(); ++i) {
		if (records[i].cost == costs) ++cnt;
	}
	printf("%d %d\n", cnt, records[0].teams);
	return;
}

int main()
{
	solve();
	return 0;
}


/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
*/