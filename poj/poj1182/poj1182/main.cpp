#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N, K;
const int maxn = 50010;
int root[maxn], mrank[maxn], relation[maxn];

void init_set()
{
	memset(root, 0, sizeof(root));
	memset(mrank, 0, sizeof(mrank));
	memset(relation, 0, sizeof(relation));
	for (int i = 1; i <= N; ++i) {
		root[i] = i; mrank[i] = 1;
	}
	return;
}

int find_root(int x)
{
	if (root[x] == x) return x;
	int r = root[x];
	root[x] = find_root(r);
	relation[x] = (relation[x]+relation[r]) % 3;
	return root[x];
}

void union_set(int type, int x, int y)
{
	int rx = find_root(x);
	int ry = find_root(y);
	if (rx == ry) return;
	if (mrank[rx] < mrank[ry]) {
		root[rx] = ry;
		mrank[ry] += mrank[rx];
		relation[rx] = (relation[y]-relation[x]+3+type-1) % 3;
	} else {
		root[ry] = rx;
		mrank[rx] += ry;
		relation[ry] = (relation[x]-relation[y]+3-(type-1)) % 3;
	}
	return;
}

bool isTrue(int type, int x, int y)
{
	if (x>N || y>N || (type==2&&x==y)) return false;
	if (find_root(x)==find_root(y)) return (relation[x]-relation[y]+3)%3 == type-1;
	return true;
}

void solve()
{
	scanf("%d %d", &N, &K);
	int cnt = 0; init_set();
	for (int i = 0; i < K; ++i)
	{
		int D, X, Y;
		scanf("%d %d %d", &D, &X, &Y);
		if (!isTrue(D, X, Y)) ++cnt;
		else union_set(D, X, Y);
	}
	printf("%d\n", cnt);
	return;
}

int main(int argc, char *argv[])
{
	solve();	
	return 0;
}