#include <iostream>
using namespace std;

const int maxn = 1e4 + 10;
int K, seq[maxn];

void solve()
{
	cin >> K;
	int max_num = 0x80000000, flag = -1;
	for (int i = 0; i < K; ++i) {
		scanf("%d", &seq[i]);
		if (seq[i] > max_num) max_num = seq[i];
	}
	if (max_num < 0) { printf("0 %d %d\n", seq[0], seq[K-1]); return; }
	else if (max_num == 0) { printf("0 0 0\n"); return; }
	int first = -1, last = -1;
	int max_first = maxn, max_last = maxn;
	int sum = 0, max_sum = 0x80000000;
	for (int i = 0; i < K; ++i)
	{
		sum += seq[i];
		if (sum >= 0) {
			if (first == -1) first = i;
			last = i;
		} else { sum = 0; first = last = -1; }
		if (sum > max_sum) { max_sum = sum; max_first = first; max_last = last; }
	}
	printf("%d %d %d\n", max_sum, seq[max_first], seq[max_last]);
	return;
}

int main()
{
	solve();
	return 0;
}


/*
6
-2 11 -4 13 -5 -2
*/