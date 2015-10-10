#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 256;
int eva_bead[maxn], shop_bead[maxn];

void solve()
{
	char ch;
	while ((ch = getchar()) != '\n') shop_bead[ch]++;
	while ((ch = getchar()) != '\n') eva_bead[ch]++;

	bool flag = true;
	for (int i = 0; i < maxn; ++i) {
		if (shop_bead[i] < eva_bead[i]) {
			flag = false; break;
		}
	}

	if (flag) {
		printf("Yes ");
		int extra = 0;
		for (int i = 0; i < maxn; ++i) extra += (shop_bead[i]-eva_bead[i]);
		printf("%d\n", extra);
	} else {
		printf("No ");
		int missing = 0;
		for (int i = 0; i < maxn; ++i) {
			if (shop_bead[i] < eva_bead[i]) missing += (eva_bead[i]-shop_bead[i]);
		}
		printf("%d\n", missing);
	}
	return;
}

int main(int argc, char *argv[])
{
	solve();
	return 0;
}