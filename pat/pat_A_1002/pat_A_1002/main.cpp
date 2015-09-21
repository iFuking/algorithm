#include <iostream>
using namespace std;

const int maxn = 1010;
float a[maxn], b[maxn];

void solve()
{
	int k1; cin >> k1;
	for (int i = 0; i < k1; ++i)
	{
		int power; float value;
		scanf("%d %f", &power, &value);
		a[power] = value;
	}
	int k2; cin >> k2;
	for (int i = 0; i < k2; ++i)
	{
		int power; float value;
		scanf("%d %f", &power, &value);
		b[power] = value;
	}

	int not_null = 0, last = -1;
	for (int i = 0; i < maxn; ++i)
	{
		a[i] += b[i];
		if (a[i] != 0) 
		{ 
			++not_null; 
			if (last == -1) last = i; 
		}
	}
	if (last == -1) { printf("0\n"); return; }
	printf("%d ", not_null);
	for (int i = maxn-1; i > last; --i) {
		if (a[i] != 0) printf("%d %.1f ", i, a[i]);
	}
	printf("%d %.1f\n", last, a[last]);
	return;
}

int main()
{
	solve();
	return 0;
}