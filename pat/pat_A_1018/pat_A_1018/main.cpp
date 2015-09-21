#include <iostream>
#include <vector>
using namespace std;

const int maxn = 510;
int c_max, N, s, M;
int sta[maxn];
int T[maxn][maxn];
vector<vector<int>> paths;
vector<int> path;
int cost = 0x7fffffff;
int visit[maxn];

void init()
{
	cin >> c_max >> N >> s >> M;
	for (int i = 1; i <= N; ++i) scanf("%d", &sta[i]);
	for (int i = 0; i < M; ++i)
	{
		int u, v; scanf("%d %d", &u, &v);
		scanf("%d", &T[u][v]);
		T[v][u] = T[u][v];
	}
	return;
}

void dfs(int st, int c)
{
	if (st==s || c>cost)
	{
		if (c > cost) return;
		if (c < cost) {
			paths.clear(); cost = c;
			paths.push_back(path);
		} else paths.push_back(path);
		return;
	}

	for (int i = 0; i <= N; ++i)
	{
		if (!visit[i] && T[st][i]>0)
		{
			visit[i] = 1;
			path.push_back(i);
			dfs(i, c+T[st][i]);
			visit[i] = 0;
			path.pop_back();
		}
	}
	return;
}

void find_path()
{
	vector<int> index, sends, takes;
	int min_send = 0x7fffffff;
	for (int i = 0; i < paths.size(); ++i)
	{
		path = paths[i];
		int send = 0, take = 0;
		for (int j = 0; j < path.size(); ++j) 
		{
			if (sta[path[j]] >= c_max/2) take += (sta[path[j]]-c_max/2);
			else {
				if (sta[path[j]]+take >= c_max/2) take -= (c_max/2-sta[path[j]]);
				else { send += (c_max/2-sta[path[j]]-take); take = 0; }
			}
		}
		if (send < min_send) {
			min_send = send;
			index.clear(); sends.clear(); takes.clear();
			index.push_back(i); 
			sends.push_back(send); takes.push_back(take);
		} else if (send == min_send) {
			index.push_back(i); 
			sends.push_back(send); takes.push_back(take);
		}
	}

	int flag, min_take = 0x7fffffff;
	for (int i = 0; i < takes.size(); ++i) {
		if (takes[i] < min_take) min_take = takes[flag=i];
	}

	printf("%d 0", sends[flag]);
	for (int i = 0; i < paths[index[flag]].size(); ++i) printf("->%d", paths[index[flag]][i]);
	printf(" %d", takes[flag]);
	return;
}

void solve()
{
	init();
	visit[0] = 1;
	dfs(0, 0);
	find_path();
	return;
}

int main(int argc, char *argv[])
{
	solve();
	return 0;
}

/*
10 5 5 9
6 2 5 7 0
0 1 1
0 2 1
0 3 1
0 4 2
0 5 3
1 4 1
2 5 3
3 5 2
4 5 1
*/