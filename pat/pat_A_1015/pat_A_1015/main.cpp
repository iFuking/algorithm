#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 32;
int N;

bool is_prime(int n)
{
	if (n==2 || n==3) return true;
	for (int i = 2; i <= sqrt(1.0*n); i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

void itoa_radix(int n, int r, char *str)
{
	int len = 0;
	while (n > 0) {
		str[len++] = n%r + '0';
		n /= r;
	}
	str[len] = '\0';
	return;
}

int rev_N(int n, int r)
{
	char str[maxn]; itoa_radix(n, r, str);
	int ans = 0, len = strlen(str);
	for (int i = 0; i < len; ++i) ans = ans*r + str[i]-'0';
	return ans;
}

void solve()
{
	int D; cin >> D;
	if (N == 1) { printf("No\n"); return; }
	int rev = rev_N(N, D);
	if (is_prime(N) && is_prime(rev)) { printf("Yes\n"); return; }
	printf("No\n");
	return;
}

int main()
{
	while (scanf("%d", &N) && N>0) solve();
	return 0;
}