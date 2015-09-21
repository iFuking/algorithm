#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int inven;
	double price;
}Mooncake;
const int maxn = 1010;
const double eps = 1e-9;
int N, D;
Mooncake mc[maxn];

bool cmp(Mooncake m1, Mooncake m2) { return m1.price > m2.price; }

void solve()
{
	cin >> N >> D;
	for (int i = 0; i < N; ++i) scanf("%d", &mc[i].inven);
	for (int i = 0; i < N; ++i) {
		scanf("%lf", &mc[i].price);
		if (mc[i].inven > 0) mc[i].price = mc[i].price/mc[i].inven;
		else mc[i].price = 0.0;
	}
	sort(mc, mc+N, cmp);

	double profit = 0.0;
	for (int i = 0; i < N && D > 0; ++i)
	{
		if (D >= mc[i].inven) {
			profit += mc[i].inven*mc[i].price;
			D -= mc[i].inven;
		} else {
			profit += D*mc[i].price;
			D = 0;
		}
	}
	printf("%.2f\n", profit);
	return;
}

int main()
{
	solve();
	return 0;
}


/*
3 100
0 150 100
7.5 7.2 4.5
*/