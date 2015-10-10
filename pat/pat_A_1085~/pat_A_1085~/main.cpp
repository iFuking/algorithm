#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 10;
int N, p;
int seq[maxn];

bool cmp(int x, int y) { return x < y; }

int b_search()
{
	int max_ans = -1;
	for (int i = N-1; i >= max_ans; --i)
	{
		int left = 0, right = i-1;
		int M = seq[i];
		while (left <= right)
		{
			int mid = (left+right) >> 1;
			if (log(M*1.0) <= log(p*1.0)+log(seq[mid]*1.0)) right = mid-1;
			else left = mid+1;
		}
		int ans = i-left+1;
		if (ans > max_ans) max_ans = ans;
	}
	return max_ans;
}

void solve()
{
	cin >> N >> p;
	for (int i = 0; i < N; ++i) scanf("%d", &seq[i]);
	sort(seq, seq+N, cmp);
	printf("%d\n", b_search());
	return;
}

int main()
{
	solve();
	return 0;
}