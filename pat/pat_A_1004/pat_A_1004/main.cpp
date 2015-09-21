#include <iostream>
#include <vector>
using namespace std;

const int maxn = 110;
int N, M;
int father[maxn], has_kids[maxn];
vector<int> leaves;
int generation_numbers[maxn];

void solve()
{
	cin >> N >> M;
	if (N == 1) { printf("1\n"); return; }
	father[1] = 1; has_kids[1] = 1;
	for (int i = 0; i < M; ++i)
	{
		int f, K; scanf("%d %d", &f, &K);
		has_kids[f] = 1;
		for (int j = 0; j < K; ++j)
		{
			int kid; scanf("%d", &kid);
			father[kid] = f;
		}
	}

	for (int i = 1; i <= N; ++i) {
		if (!has_kids[i]) leaves.push_back(i);
	}

	int max_gen = 0;
	for (int i = 0; i < leaves.size(); ++i)
	{
		int gen = 1, fa = father[leaves[i]];
		for ( ; fa != 1; fa = father[fa]) ++gen;
		if (gen > max_gen) max_gen = gen;
		generation_numbers[gen]++;
	}

	for (int i = 0; i < max_gen; ++i) printf("%d ", generation_numbers[i]);
	printf("%d\n", generation_numbers[max_gen]);
	return;
}

int main()
{
	solve();
	return 0;
}

/*
4 2
01 2 02 03
03 1 04

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