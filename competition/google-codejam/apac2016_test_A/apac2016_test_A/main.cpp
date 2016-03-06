#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

const int maxlen = 81;
const int maxn = 205;
int T, M;
bool has_path[maxn][maxn], visit[maxn];
int group[maxn];
FILE *fp = NULL;

void bfs(int vertex)
{
	queue<int> q; q.push(vertex);
	visit[vertex] = true;
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		for (int i = 1; i <= 2*M; ++i)
		{
			if (!visit[i] && has_path[v][i]) {
				visit[i] = true;
				group[i] = !group[v];
				q.push(i);
			}
		}
	}
	return;
}

void solve()
{
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		map<string, int> name2id;
		memset(has_path, 0, sizeof(has_path));
		int index = 1; scanf("%d", &M);
		for (int i = 0; i < M; ++i)
		{
			char name1[maxlen], name2[maxlen];
			scanf("%s %s", name1, name2);
			if (name2id[name1] == 0) name2id[name1] = index++;
			if (name2id[name2] == 0) name2id[name2] = index++;
			has_path[name2id[name1]][name2id[name2]] = true;
			has_path[name2id[name2]][name2id[name1]] = true;
		}

		memset(visit, 0, sizeof(visit));
		memset(group, 0, sizeof(group));
		map<string, int>::iterator iter = name2id.begin();
		group[iter->second] = 1;
		bfs(iter->second);

		bool flag = false;
		for (int i = 1; i <= 2*M; ++i) {
			for (int j = 1; j <= 2*M; ++j) {
				if (has_path[i][j] && group[i]==group[j]) {
					flag = true; goto out;
				}
			}
		}
out:
/*
		printf("Case #%d: ", t);
		if (!flag) printf("Yes\n");
		else printf("No\n");
*/
		fp = fopen("E:\\foo.txt", "a");
		fprintf(fp, "Case #%d: ", t);
		if (!flag) fprintf(fp, "Yes\n");
		else fprintf(fp, "No\n");
	}
	return;
}

int main()
{
	solve();
	return 0;
}