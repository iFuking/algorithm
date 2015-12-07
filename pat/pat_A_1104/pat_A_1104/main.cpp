#include <iostream>
using namespace std;

const int maxn = 1e5 + 10;
double arr[maxn];

void solve()
{
	int N; cin >> N;
	for (int i = 0; i < N; ++i) scanf("%lf", &arr[i]);

	double ans = 0.0;
	for (int i = 0; i < N; ++i) ans += arr[i]*(i+1)*(N-i);
	printf("%.2f\n", ans);
	return;
}

int main()
{
	solve();
	return 0;
}