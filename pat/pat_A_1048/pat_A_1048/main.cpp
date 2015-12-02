#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int coins[maxn];

void solve()
{
	int N, target; cin >> N >> target;
	for (int i = 0; i < N; ++i) scanf("%d", &coins[i]);
	sort(coins, coins+N);

	int head = 0, tail = N-1;
	while (head < tail) {
		if (coins[head]+coins[tail] < target) ++head;
		else if (coins[head]+coins[tail] > target) --tail;
		else {
			printf("%d %d\n", coins[head], coins[tail]);
			return;
		}
	}
	printf("No Solution\n");
	return;
}

int main()
{
	solve();
	return 0;
}