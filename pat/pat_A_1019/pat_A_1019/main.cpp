#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 1e9 + 10;
const int maxlen = 31;  // log(maxn)/log(2)
int N, b, len;
int res[maxlen];

void solve()
{
	
	cin >> N >> b;
	while (N) {
		res[len++] = N % b;
		N /= b;
	}
	
	int i;
	for (i = len-1; i >= len/2; --i) {
		if (res[i] != res[len-1-i]) { printf("No\n"); break; }
	}
	if (i == len/2-1) printf("Yes\n");

	for (int j = len-1; j >= 1; --j) printf("%d ", res[j]);
	printf("%d\n", res[0]);
	return;
}

int main(int argc, char *argv[])
{
	solve();
	return 0;
}