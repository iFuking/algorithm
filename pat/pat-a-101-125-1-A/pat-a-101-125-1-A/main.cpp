#include <iostream>
using namespace std;

const int maxn = 256;
int shop[maxn], eva[maxn];

void solve()
{
	char ch;
	while ((ch=getchar()) != '\n') shop[ch]++;
	while ((ch=getchar()) != '\n') eva[ch]++;

	int flag = false;
	int miss = 0, extra = 0;
	for (int i = 0; i < maxn; ++i) {
		if (shop[i] < eva[i]) {
			flag = true;
			miss += (eva[i]-shop[i]);
		} else extra += (shop[i]-eva[i]);
	}
	if (flag) printf("No %d\n", miss);
	else printf("Yes %d\n", extra);
	return;
}

int main(int argc, char *argv[])
{
	solve();
	return 0;
}

// score (20): 20