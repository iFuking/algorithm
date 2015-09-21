#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int bugs_numbers, interactions;
const int maxn = 2010, max_inter = 1000010;
int father[maxn], height[maxn];
int relation[maxn];
int interaction_pair[max_inter][2];

void init_set()
{
	memset(father, 0, sizeof(father));
	memset(height, 0, sizeof(height));
	memset(relation, 0, sizeof(relation));
	memset(interaction_pair, 0, sizeof(interaction_pair));
	for (int i = 0; i < bugs_numbers; ++i) father[i] = i;
	return;
}

int find_set(int x)
{
	if (father[x] == x) return x;
	int fx = father[x];
	father[x] = find_set(fx);
	relation[x] = relation[x]^relation[fx];
	return father[x];
}

void union_set(int x, int y)
{
	int fx = find_set(x);
	int fy = find_set(y);
	if (fx == fy) return;
	if (height[fx] < height[fy]) {
		father[fx] = fy;
		relation[fx] = ~(relation[x]^relation[y]);
	} else {
		if (height[fx] == height[fy]) ++height[fx];
		father[fy] = fx;
		relation[fy] = ~(relation[x]^relation[y]);
	}
	return;
}

bool solve(int x, int y)
{
	if (find_set(x)==find_set(y) && relation[x]==relation[y]) return false;
	return true;
}

void print_msg(int scen, bool flag)
{
	if (flag) printf("Scenario #%d:\nSuspicious bugs found!\n\n", scen);
	else printf("Scenario #%d:\nNo suspicious bugs found!\n\n", scen);
	return;
}

int main(int argc, char *argv[])
{
	int scenarios; cin >> scenarios;
	for (int scen = 1; scen <= scenarios; ++scen)
	{
		scanf("%d %d", &bugs_numbers, &interactions);
		init_set();
		for (int i = 0; i < interactions; ++i) 
			scanf("%d %d", &interaction_pair[i][0], &interaction_pair[i][1]);
		bool flag = false;
		for (int i = 0; i < interactions; ++i)
		{
			union_set(interaction_pair[i][0], interaction_pair[i][1]);
			if (!solve(interaction_pair[i][0], interaction_pair[i][1])) {
				flag = true; break;
			}
		}
		print_msg(scen, flag);
	}
	return 0;
}