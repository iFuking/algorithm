#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 1e3 + 10;
const double eps = 1e-9;
int n, m, x, y, t;
double pool[maxn][maxn], avg = 0.0;

void solve()
{
	cin >> n >> m >> x >> y >> t;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%lf", &pool[i][j]);
			avg += pool[i][j];
		}
	}
	avg /= (m*n);

	double pcc = pow(1.0-pool[x][y], t-1)*pool[x][y];
	double pss = pow(1.0-avg, t-1)*avg;
	if (fabs(pcc-pss) < eps) printf("equal\n%.4f\n", pcc);
	else if (pcc > pss) printf("cc\n%.4f\n", pcc);
	else printf("ss\n%.4f\n", pss);
	return;
}

int main()
{
	solve();
	return 0;
}