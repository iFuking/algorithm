#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 50010;
int uset[maxn];
int rank[maxn];
int n, m;

void init_set()
{
	memset(uset, 0, sizeof(uset));
	memset(rank, 0, sizeof(rank));
	for (int i = 1; i <= n; ++i) uset[i] = i;
	return;
}

int find_set(int x)
{
	return uset[x]==x ? x : uset[x]=find_set(uset[x]);
}

void union_set(int x, int y)
{
	int ux = find_set(x);
	int uy = find_set(y);
	if (ux == uy) return;
	if (rank[ux] > rank[uy]) uset[uy] = ux;
	else {
		if (rank[ux] == rank[uy]) rank[uy]++;
		uset[ux] = uy;
	}
	return;
}

int main(int argc, char *argv[])
{
	int cases = 1;
	while (scanf("%d %d", &n, &m) && n && m)
	{
		init_set();
		int u, v;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d", &u, &v);
			union_set(u, v);
		}
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
			if (uset[i] == i) ++cnt;
		printf("Case %d: %d\n", cases, cnt);
		++cases;
	}
	return 0;
}