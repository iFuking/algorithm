#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 1e5 + 10;
int N, p;
int seq[maxn];

bool cmp(int x, int y) { return x < y; }

int search_m()
{
	int max_nums = 0x80000000;
	for (int i = N-1; i >= 0; --i)
	{
		int M = seq[i];
		int lm = 0, rm = i;
		while (lm <= rm)
		{
			int midm = (lm+rm) >> 1;
			if (log(M*1.0) > log(seq[midm]*1.0)+log(p*1.0)) lm = midm+1;
			else rm = midm-1;
		}
		if (i-lm+1 > max_nums) max_nums = i-lm+1;
		if (i < max_nums) break;
	}
	return max_nums;
}

int search_M()
{
	int max_nums = 0x80000000;
	for (int i = 0; i < N; ++i)
	{
		int m = seq[i];
		int lm = i, rm = N-1;
		while (lm <= rm)
		{
			int midm = (lm+rm) >> 1;
			if (log(seq[midm]*1.0) > log(m*1.0)+log(p*1.0)) rm = midm-1;
			else lm = midm+1;
		}
		if (rm-i+1 > max_nums) max_nums = rm-i+1;
		if (N-i < max_nums) break;
	}
	return max_nums;
}

void solve()
{
	cin >> N >> p;
	for (int i = 0; i < N; ++i) scanf("%d", &seq[i]);
	sort(seq, seq+N, cmp);
	int max1 = search_m();
	int max2 = search_M();
	printf("%d\n", max1>max2?max1:max2);
	return;
}

int main(int argc, char *argv[])
{
	solve();
	return 0;
}