#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-9;
const int maxn = 2e3 + 10;
int pedal[maxn], extra[maxn], tire[maxn];

bool cmp(const int &a, const int &b) { return a < b; }

void solve()
{
	FILE *fp = NULL;
	fp = fopen("e:\\b_out.txt", "w");
	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		int np, ne, nt; scanf("%d %d %d", &np, &ne, &nt);
		for (int i = 0; i < np; ++i) scanf("%d", &pedal[i]);
		sort(pedal, pedal+np, cmp);
		for (int i = 0; i < ne; ++i) scanf("%d", &extra[i]);
		sort(extra, extra+ne, cmp);
		for (int i = 0; i < nt; ++i) scanf("%d", &tire[i]);
		sort(tire, tire+nt, cmp);
		int M; scanf("%d", &M);
		fprintf(fp, "Case #%d:\n", t);
		printf("Case #%d:\n", t);
		while (M--)
		{
			double p, q; scanf("%lf %lf", &p, &q);
			bool flag = false;
			for (int i = 0; i < np; ++i) {
				for (int j = 0; j < ne; ++j) {
					for (int k = 0; k < ne; ++k) {
						if (k != j) {
							for (int l = 0; l < nt; ++l) {
								if (fabs(1.0*pedal[i]/extra[j]*extra[k]/tire[l]-p/q) < eps) {
									fprintf(fp, "Yes\n");
									printf("Yes\n"); flag = true; goto out;
								}
							}
						}
					}
				}
			}
out:
			if (!flag) {
				fprintf(fp, "No\n"); printf("No\n");
			}
		}
	}
	return;
}

int main()
{
	solve();
	return 0;
}