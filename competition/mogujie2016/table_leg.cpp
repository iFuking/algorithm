#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef struct {
	int leg_len;
	int leg_cst;
}LEG;

const int INF = 0x7fffffff;
const int maxn = 1e3 + 10;
LEG leg[maxn];

bool cmp(const LEG &l1, const LEG &l2) {
	return l1.leg_cst < l2.leg_cst;
}

void solve() {
	map<int, int> len_cnt;

	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int leg_lenth; scanf("%d", &leg_lenth);
		leg[i].leg_len = leg_lenth;
		++len_cnt[leg_lenth];
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &leg[i].leg_cst);
	}

	sort(leg, leg+n, cmp);

	int min_cost = INF;
	map<int, int>::iterator iter = len_cnt.begin();
	for ( ; iter != len_cnt.end(); ++iter) {
		int cost = 0, cnt = n-iter->second;
		for (int i = 0; i < n; ++i) {
			if (leg[i].leg_len > iter->first) {
				cost += leg[i].leg_len;
				--cnt;
			}
		}

		for (int i = 0; i<n && cnt>=iter->second; ++i) {
			if (leg[i].leg_len < iter->first) {
				cost += leg[i].leg_len;
				--cnt;
			}
		}

		min_cost = min(min_cost, cost);
	}

	printf("%d\n", min_cost);
	return;
}

int main() {
	solve();
	return 0;
}