#include <iostream>
#include <cstdio>
using namespace std;

bool meet_condition1(int n) {
	while (n) {
		if (n%10==2 || n%10==3 || n%10==5) return true;
		n /= 10;
	}
	return false;
}

bool meet_condition2(int n) {
	int pre = -1;
	while (n) {
		if (pre==8 && n%10==1) return false;
		pre = n%10;
		n /= 10;
	}
	return true;
}

void solve() {
	int S; cin >> S;
	while (S--) {
		int n, m; scanf("%d %d", &n, &m);
		while (n % 7) ++n;

		int cnt = 0;
		for (int i = n; i <= m; i += 7) {
			if (meet_condition1(i) && meet_condition2(i)) {
				++cnt;
			}
		}
		printf("%d\n", cnt);
	}
	return;
}

int main() {
	solve();
	return 0;
}