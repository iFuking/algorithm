/*
5 4
2 0 1
2 2 3
2 3 4
2 1 2
*/
#include <cstdio>
#include <cstring>

const int maxn = 30010;
int n, m;
int uset[maxn], rank[maxn], num[maxn];

void init_set()
{
	memset(uset, 0, sizeof(uset));
	memset(rank, 0, sizeof(rank));
	memset(num, 0, sizeof(num));
	for (int i = 0; i < n; ++i) { uset[i] = i; num[i] = 1; }
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
	if (rank[ux] > rank[uy]) {
		uset[uy] = ux; num[ux] += num[uy];
	} else {
		if (rank[ux] == rank[uy]) ++rank[uy];
		uset[ux] = uy; num[uy] += num[ux];
	}
	return;
}

int main(int argc, char *argv[])
{
	while (scanf("%d %d", &n, &m) && (n||m))
	{
		init_set();
		for (int i = 0; i < m; ++i)
		{
			int k; scanf("%d", &k);
			int u, v; scanf("%d", &u);
			for (int j = 0; j < k-1; ++j) 
			{
				scanf("%d", &v);
				union_set(u, v);
			}
		}
		printf("%d\n", num[find_set(0)]);
	}
	return 0;
}