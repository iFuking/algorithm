#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int coupon[maxn], value[maxn];

void solve()
{
	int nc; cin >> nc;
	for (int i = 0; i < nc; ++i) scanf("%d", &coupon[i]);
	sort(coupon, coupon+nc);
	int np; cin >> np;
	for (int i = 0; i < np; ++i) scanf("%d", &value[i]);
	sort(value, value+np);

	long long res = 0LL;
	int i = 0, j = 0;
	for ( ; i<nc && j<np && coupon[i]<0 && value[j]<0; ++i, ++j) res += coupon[i]*value[j];
	i = nc-1, j = np-1;
	for ( ; i>=0 && j>=0 && coupon[i]>0 && value[j]>0; --i, --j) res += coupon[i]*value[j];
	printf("%lld\n", res);
	return;
}

int main()
{
	solve();
	return 0;
}


/*
4
1 2 4 9
4
7 6 -2 -3
*/