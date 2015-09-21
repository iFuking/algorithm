#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 30010;
int root[maxn], m_rank[maxn];
int depth[maxn];

void init()
{
	memset(root, 0, sizeof(root));
	memset(m_rank, 0, sizeof(m_rank));
	memset(depth, 0, sizeof(depth));
	for (int i = 0; i < maxn; ++i) {
		root[i] = i; m_rank[i] = 1;
	}
	return;
}

int find_root(int x)
{
	if (root[x] == x) return x;
	int r = root[x];
	root[x] = find_root(r);
	depth[x] += depth[r];
	return root[x];
}

void union_set(int x, int y)
{
	int rx = find_root(x);
	int ry = find_root(y);
	if (rx == ry) return;
	root[ry] = rx;
	depth[ry] = m_rank[rx];
	m_rank[rx] += m_rank[ry];
	return;
}

void solve()
{
	int P; cin >> P;
	init();
	while (P--)
	{
		getchar();
		char op; scanf("%c", &op);
		if (op == 'M') {
			int cube1, cube2; scanf("%d %d", &cube1, &cube2);
			union_set(cube1, cube2);
		} else {
			int cube; scanf("%d", &cube);
			printf("%d\n", m_rank[find_root(cube)]-depth[cube]-1);
		}
	}
	return;
}

int main(int argc, char *argv[])
{
	solve();
	return 0;
}