#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxk = 2505;
vector<vector<string>> course(maxk);

bool cmp(const string &s1, const string &s2) { return s1 < s2; }

void solve()
{
	int N, K; cin >> N >> K;
	char name[5]; int c, crs;
	for (int i = 0; i < N; ++i) {
		scanf("%s %d", name, &c);
		for (int j = 0; j < c; ++j) {
			scanf("%d", &crs);
			course[crs].push_back(string(name));
		}
	}

	for (int i = 1; i <= K; ++i) {
		sort(course[i].begin(), course[i].end(), cmp);
		printf("%d %d\n", i, course[i].size());
		for (int j = 0; j < course[i].size(); ++j) printf("%s\n", course[i][j].c_str());
	}
	return;
}

int main()
{
	solve();
	return 0;
}