#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100010;
int father[maxn], height[maxn];
int relation[maxn];
int n, m;

void init_set()
{
	memset(father, 0, sizeof(father));
	memset(height, 0, sizeof(height));
	memset(relation, 0, sizeof(relation));
	for (int i = 1; i <= n; ++i) father[i] = i;
	return;
}

int find_set(int x)
{
	if (father[x] == x) return x;
	int p = father[x];
	father[x] = find_set(p);
	relation[x] = relation[x] ^ relation[p];
	return father[x];
}

void union_set(int x, int y)
{
	int fx = find_set(x);
	int fy = find_set(y);
	if (fx == fy) return;
	// relation(x, fx) is relation[x], relation(x, y) is 1, relation(y, fy) is relation[y]
	// update relation(fx, fy)
	if (height[fx] > height[fy]) {
		father[fy] = fx;
		relation[fy] = ~(relation[x]^relation[x]);
	} else {
		if (height[fx] == father[fy]) ++height[fy];
		father[fx] = fy;
		relation[fx] = ~(relation[x]^relation[y]);
	}
	return;
}

void ast(int c1, int c2)
{
	if (find_set(c1) != find_set(c2)) printf("Not sure yet.\n");
	else if (relation[c1] == relation[c2]) printf("In the same gang.\n");
	else printf("In different gangs.\n");
	return;
}

int main(int argc, char *argv[])
{
	int T;  cin >> T;
	while (T--)
	{
		cin >> n >> m;
		init_set();
		for (int msg = 0; msg < m; ++msg)
		{
			char cmd; int c1, c2; getchar();
			scanf("%c %d %d", &cmd, &c1, &c2);
			if (cmd == 'A') ast(c1, c2);
			else if (cmd == 'D') union_set(c1, c2);
		}
	}
	return 0;
}