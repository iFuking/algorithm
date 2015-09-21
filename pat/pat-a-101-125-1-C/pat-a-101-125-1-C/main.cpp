#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 110;
int father[maxn], cnt[maxn];
int N, M;

void solve()
{
	cin >> N >> M;
	if (M == 0) { printf("1 1\n"); return; }
	int node_nums = 0;
	for (int i = 0; i < M; ++i)
	{
		char father_id[3]; int kid_nums;
		scanf("%s %d", father_id, &kid_nums);
		for (int j = 0; j < kid_nums; ++j)
		{
			char kid_id[3]; scanf("%s", &kid_id);
			father[atoi(kid_id)] = atoi(father_id);
		}
	}

	int father_id;
	for (int i = 1; i <= N; ++i) {
		if (father[i] == 0) father_id = i;
	}

	for (int i = 1; i <= N; ++i)
	{
		int gen = 1, f = father[i];
		if (!f) continue;
		for ( ; f != father_id; f = father[f], ++gen) ;
		cnt[gen]++;
	}

	int max_gen = -1, flag;
	for (int i = 1; i <= maxn; ++i) {
		if (cnt[i] > max_gen) max_gen = cnt[flag=i];
	}
	printf("%d %d\n", cnt[flag], flag+1);
	return;
}

int main(int argc, char *argv[])
{
	solve();
	return 0;
}


/*
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
*/


// score (25): 25