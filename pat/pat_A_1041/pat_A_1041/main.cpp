#include <iostream>
using namespace std;

const int maxhash = 1e4 + 10;
int hash_num[maxhash];
const int maxn = 1e5 + 10;
int num[maxn];

void solve()
{
	int N; cin >> N;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &num[i]);
		++hash_num[num[i]];
	}

	int flag = -1;
	for (int i = 0; i < N; ++i) {
		if (hash_num[num[i]] == 1) { flag = i; break; }
	}
	if (flag == -1) { printf("None\n"); return; }
	printf("%d\n", num[flag]);
	return;
}

int main()
{
	solve();
	return 0;
}