#include <iostream>
using namespace std;

void solve()
{
	int g1, s1, k1; scanf("%d.%d.%d", &g1, &s1, &k1);
	int g2, s2, k2; scanf("%d.%d.%d", &g2, &s2, &k2);
	int incr_s = 0, incr_g = 0;
	if (k1+k2 >= 29) ++incr_s;
	if (s1+s2+incr_s >= 17) ++incr_g;
	printf("%d.%d.%d\n", g1+g2+incr_g, (s1+s2+incr_s)%17, (k1+k2)%29);
	return;
}

int main()
{
	solve();
	return 0;
}