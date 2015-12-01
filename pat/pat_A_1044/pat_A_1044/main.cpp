#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5 + 10;
int value[maxn], sum[maxn];

void solve()
{
	int N, target; cin >> N >> target;
	for (int i = 0; i < N; ++i) scanf("%d", &value[i]);

	int pt = 0, s = 0, meet_target = 0x3f3f3f3f;
	vector<pair<int, int>> chain;
	for (int i = 0; i < N; ++i) {
		s += value[i];
		while (pt<=i && s-value[pt]>=target) s -= value[pt++];
		sum[i] = s;
		
		if (sum[i]>=target && sum[i]<=meet_target) {
			if (sum[i] < meet_target) {
				meet_target = sum[i]; chain.clear();
			}
			chain.push_back(make_pair(pt, i));
		}
	}

	for (int i = 0; i < chain.size(); ++i) printf("%d-%d\n", chain[i].first+1, chain[i].second+1);
	return;
}

int main()
{
	solve();
	return 0;
}