#include <iostream>
#include <algorithm>
#include <cstring>
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
double delta(double x, double y) { return x>y ? x-y : y-x; }

void solve()
{
	while (scanf("%d %d", &n, &k)!=EOF && n)
	{
		memset(foo, 0, sizeof(foo));
		for (int i = 0; i < n; ++i) scanf("%d", &foo[i].a);
		for (int i = 0; i < n; ++i) scanf("%d", &foo[i].b);
		double r = 0.0, r_copy = 1.0;
		while (delta(r, r_copy) > eps)
		{
			r_copy = r;
			for (int i = 0; i < n; ++i) foo[i].c = foo[i].a-r*foo[i].b;
			sort(foo, foo+n, cmp);
			double sum_a = 0.0, sum_b = 0.0;
			for (int i = 0; i < n-k; ++i) { sum_a += foo[i].a; sum_b += foo[i].b; }
			r = sum_a/sum_b;
		}
		printf("%1.0f\n", r*100);
	}
	return;
}

int main()
{
	solve();
	return 0;
}


/*
3 1
5 0 2
5 1 6
4 2
1 2 7 9
5 6 7 9
0 0
*/