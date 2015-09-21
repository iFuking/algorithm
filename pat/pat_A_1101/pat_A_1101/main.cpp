#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5 + 10;
int N, a[maxn];
int to_left[maxn], to_right[maxn];

void solve()
{
	cin >> N;
	for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
	
	int max_number = -1;
	for (int i = 0; i < N; ++i) {
		if (a[i] > max_number) max_number = a[i];
		to_left[i] = max_number;
	}
	int min_number = 0x7fffffff;
	for (int i = N-1; i >= 0; --i) {
		if (a[i] < min_number) min_number = a[i];
		to_right[i] = min_number;
	}

	vector<int> res;
	for (int i = 0; i < N; ++i) {
		if (a[i]>=to_left[i] && a[i]<=to_right[i]) res.push_back(a[i]);
	}

	printf("%d\n", res.size());
	if (res.size() == 0) { printf("\n"); return; }
	for (int i = 0; i < res.size()-1; ++i) printf("%d ", res[i]);
	printf("%d\n", res[res.size()-1]);
	return;
}

int main()
{
	solve();
	return 0;
}