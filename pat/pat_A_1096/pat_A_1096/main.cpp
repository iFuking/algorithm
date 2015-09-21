#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> res;

bool is_prime(int n)
{
	if (n==2 || n==3) return true;
	for (int i = 2; i <= sqrt(1.0*n); ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

void solve()
{
	int N, max_size = 0; cin >> N;
	if (is_prime(N)) { printf("1\n%d\n", N); return; }
	for (int fac_begin = 2; fac_begin <= sqrt(1.0*N); ++fac_begin)
	{
		int n = N, i = fac_begin;
		vector<int> v;
		while (n % i == 0)
		{
			v.push_back(i);
			n /= i; ++i;
		}
		if (v.size() > max_size) { max_size = v.size(); res = v; }
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size()-1; ++i) printf("%d*", res[i]);
	printf("%d\n", res[res.size()-1]);
	return;
}

int main()
{
	solve();
	return 0;
}