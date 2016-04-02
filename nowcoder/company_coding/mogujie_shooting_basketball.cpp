#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

const int maxn = 3e2 + 10;
int x[maxn];

void solve() {
	int p, n;
	while (scanf("%d %d", &p, &n) != EOF) {
		map<int, int> m;
		bool flag = false;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x[i]);
		}

		for (int i = 0; i < n; ++i) {	
			int p_num = x[i] % p;
			if (m[p_num] > 0) {
				flag = true;
				printf("%d\n", i+1);
				break;
			}
			++m[p_num];
		}
		if (!flag) {
			printf("-1\n");
		}
	}
	return;
}

int main() {
	solve();
	return 0;
}