#include <iostream>
using namespace std;

long long reverse_number(long long n)
{
	long long ans = 0;
	while (n) {
		ans = ans*10 + n%10;
		n /= 10;
	}
	return ans;
}

void solve()
{
	long long N; cin >> N;
	int K; cin >> K;
	for (int i = 0; i < K; ++i) {
		long long reverse_N = reverse_number(N);
		if (N == reverse_N) {
			printf("%lld\n%d\n", N, i);
			return;
		}
		N = N+reverse_N;
	}
	printf("%lld\n%d\n", N, K);
	return;
}

int main()
{
	solve();
	return 0;
}