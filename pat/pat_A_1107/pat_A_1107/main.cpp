#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 1e3 + 10;
int father[maxn];
map<int, vector<int>> person, hobby;

int find_fa(int x) { return x==father[x] ? x : father[x]=find_fa(father[x]); }

bool cmp(const int &n1, const int &n2) { return n1 > n2; }

void solve()
{
	int N; cin >> N;
	for (int i = 1; i <= N; ++i) {
		int K; scanf("%d:", &K);
		for (int j = 0; j < K; ++j) {
			int h; scanf("%d", &h);
			person[i].push_back(h);
			hobby[h].push_back(i);
		}
	}

	for (int i = 1; i <= N; ++i) father[i] = i;
	map<int, vector<int>>::iterator iter = hobby.begin();
	for ( ; iter != hobby.end(); ++iter) {
		if (iter->second.size() > 1) {
			vector<int>::iterator it = iter->second.begin();
			int fx = find_fa(*iter->second.begin());
			for ( ; it != iter->second.end(); ++it) {
				int fy = find_fa(*it);
				if (fx != fy) father[fy] = fx;
			}
		}
	}

	iter = person.begin();
	for ( ; iter != person.end(); ++iter) {
		vector<int>::iterator it = iter->second.begin();
		for ( ; it != iter->second.end(); ++it) {
			vector<int>::iterator ii = hobby[*it].begin();
			int fx = find_fa(*hobby[*it].begin());
			for ( ; ii != hobby[*it].end(); ++ii) {
				if (hobby[*it].size() > 1) {
					int fy = find_fa(*ii);
					if (fx != fy) father[fy] = fx;
				}
			}
		}
	}

	map<int, int> cnt;
	for (int i = 1; i <= N; ++i) ++cnt[father[i]];
	vector<int> ans;
	map<int, int>::iterator it = cnt.begin();
	for ( ; it != cnt.end(); ++it) ans.push_back(it->second);
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size()-1; ++i) printf("%d ", ans[i]);
	printf("%d\n", ans[ans.size()-1]);
	return;
}

int main()
{
	solve();
	return 0;
}