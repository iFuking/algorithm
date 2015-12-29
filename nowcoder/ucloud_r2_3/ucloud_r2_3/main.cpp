#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int maxn = 1e6 + 10;
long long euler[maxn];
long long f[maxn];
const int M = 10007;

class GcdAndPhi {
public:
	void eule()
	{
		euler[1] = 1;
		for (int i = 2; i < maxn; i++)
			euler[i] = i;
		for (int i = 2; i < maxn; i++)
			if (euler[i] == i)
				for (int j = i; j < maxn; j += i)
					euler[j] = euler[j]/i*(i-1);
	}

	int gcd(int a, int b)
	{
		if (a%b == 0) return b;
		return gcd(b, a%b);
	}

	long long fn(int n)
	{
		if (f[n]) return f[n];
		long long sum = 0L;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j < i; ++j) {
				sum += euler[gcd(euler[i], euler[j])]%M;
			}
		}
		sum = sum*2%M;
		for (int i = 1; i <= n; ++i) sum += euler[euler[i]]%M;
		return sum%M;
	}

    vector<long long> calc(int T, vector<int> N) {
		vector<long long> ans;
		eule();
		for (int i = 0; i < T; ++i) ans.push_back(fn(N[i]));
		return ans;
    }
};

int main()
{
	int a[] = {41, 4, 26, 5, 14};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	GcdAndPhi sol;
	sol.calc(5, v);
	return 0;
}
