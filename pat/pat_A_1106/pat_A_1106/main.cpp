#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

void solve()
{
	int N; cin >> N;
	double p, r; cin >> p >> r;
	map<int, vector<int>> sup;
	for (int i = 0; i < N; ++i)
	{
		int K; scanf("%d", &K);
		for (int j = 0; j < K; ++j) {
			int id; scanf("%d", &id);
			sup[i].push_back(id);
		}
		if (K == 0) sup[i].push_back(0);
	}

	queue<int> q; int depth = 0, cnt = 0;
	q.push(0); q.push(-1);
	while (!q.empty()) {
		int id = q.front(); q.pop();
		if (id == -1) {
			++depth; q.push(-1);
			if (cnt > 0) break;
			continue;
		}
		if (sup[id].size()==1 && sup[id][0]==0) { ++cnt; continue; }
		for (int i = 0; i < sup[id].size(); ++i) {
			q.push(sup[id][i]);
		}
	}
	printf("%.4f %d\n", p*pow(1+0.01*r, depth-1), cnt);
	return;
}

int main()
{
	solve();
	return 0;
}
