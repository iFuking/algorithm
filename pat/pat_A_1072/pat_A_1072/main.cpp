#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct {
	int index;
	int min_dist;
	int total_dist;
}Solution;
const int maxn = 1100;
const int maxch = 15;
const int inf = 0x3fffffff;
int N, M, K, D;
int dist[maxn][maxn], d[maxn];
bool visit[maxn];
vector<Solution> sol;

bool dijkstra(int s)
{
	memset(visit, 0, sizeof(visit));
	visit[s] = true;
	for (int i = 1; i <= N+M; ++i) d[i] = dist[s][i];
	for (int i = 1; i < N+M; ++i)  // iterate N+M-1 times
	{
		int shortest = inf, flag;
		for (int j = 1; j <= N+M; ++j) {
			if (!visit[j] && d[j]<shortest) shortest = d[flag=j];
		}
		for (int j = 1; j <= N+M; ++j) {
			if (!visit[j] && dist[flag][j]!=inf) d[j] = min(d[j], d[flag]+dist[flag][j]);
		}
		visit[flag] = true;
		if (d[flag] > D) return false;
	}
	return true;
}

bool cmp(const Solution &s1, const Solution &s2)
{
	if (s1.min_dist != s2.min_dist) return s1.min_dist > s2.min_dist;
	else if (s1.total_dist != s2.total_dist) return s1.total_dist < s2.total_dist;
	return s1.index < s2.index;
}

void solve()
{
	cin >> N >> M >> K >> D;
	for (int i = 0; i <= N+M; ++i) {
		for (int j = 0; j <= N+M; ++j) {
			dist[i][j] = inf;
			if (i == j) dist[i][j] = 0;
		}
	}
	for (int i = 0; i < K; ++i)
	{
		char pos1[maxch], pos2[maxch];
		int p1, p2;
		int distance;
		scanf("%s %s %d", pos1, pos2, &distance);
		if (pos1[0] == 'G') {
			for (int j = 0; j < strlen(pos1)-1; ++j) pos1[j] = pos1[j+1];
			pos1[strlen(pos1)-1] = '\0';
			p1 = atoi(pos1) + N;
		} else p1 = atoi(pos1);
		if (pos2[0] == 'G') {
			for (int j = 0; j < strlen(pos2)-1; ++j) pos2[j] = pos2[j+1];
			pos2[strlen(pos2)-1] = '\0';
			p2 = atoi(pos2) + N;
		} else p2 = atoi(pos2);
		dist[p1][p2] = distance;
		dist[p2][p1] = distance;
	}

	for (int i = 1; i <= M; ++i) {
		if (dijkstra(i+N)) {
			Solution s; s.index = i;
			s.min_dist = 1.0*inf, s.total_dist = 0.0;
			for (int j = 1; j <= N; ++j) {
				if (d[j] < s.min_dist) s.min_dist = d[j];
				s.total_dist += d[j];
			}
			sol.push_back(s);
		}
	}
	if (sol.size() == 0) { printf("No Solution\n"); return; }
	sort(sol.begin(), sol.end(), cmp);
	printf("G%d\n%.1f %.1f\n", sol[0].index, sol[0].min_dist*1.0, sol[0].total_dist*1.0/N);
	return;
}

int main()
{
	solve();
	return 0;
}


/*
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
*/