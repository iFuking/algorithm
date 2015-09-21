#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

typedef struct {
	int a, b;
	double c;
}Foo;

const int maxn = 1010;
Foo foo[maxn];
int n, k;
const double eps = 1e-4;

bool cmp(Foo f1, Foo f2) { return f1.c > f2.c; }

void solve()
{
	while (scanf("%d %d", &n, &k)!=EOF && n)
	{
		memset(foo, 0, sizeof(foo));
		for (int i = 0; i < n; ++i) scanf("%d", &foo[i].a);
		for (int i = 0; i < n; ++i) scanf("%d", &foo[i].b);
		double left = 0.0, right = 1.0;
		while (left+eps < right)
		{
			double mid = (left+right) / 2.0;
			for (int i = 0; i < n; ++i) foo[i].c = foo[i].a-mid*foo[i].b;
			sort(foo, foo+n, cmp);
			double sum = 0;
			for (int i = 0; i < n-k; ++i) sum += foo[i].c;
			if (sum < 0) right = mid;
			else left = mid;
		}
		printf("%1.0f\n", left*100);
	}
	return;
}

int main()
{
	solve();
	return 0;
}