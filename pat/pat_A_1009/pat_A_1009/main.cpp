#include <iostream>
#include <vector>
using namespace std;

const int maxn = 2010;
vector<pair<int, float>> a, b;
float sum[maxn];
vector<pair<int, float>> s;

void solve()
{
	int k1, k2;
	cin >> k1;
	for (int i = 0; i < k1; ++i) {
		int index; float value;
		scanf("%d %f", &index, &value);
		a.push_back(make_pair(index, value));
	}
	cin >> k2;
	for (int i = 0; i < k2; ++i) {
		int index; float value;
		scanf("%d %f", &index, &value);
		b.push_back(make_pair(index, value));
	}

	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			sum[a[i].first+b[j].first] += a[i].second*b[j].second;
		}
	}
	for (int i = maxn-1; i >= 0; --i) {
		if (sum[i] != 0) s.push_back(make_pair(i, sum[i]));
	}
	printf("%d ", s.size());
	if (s.size() == 0) return;
	for (int i = 0; i < s.size()-1; ++i) printf("%d %.1f ", s[i].first, s[i].second);
	printf("%d %.1f\n", s[s.size()-1].first, s[s.size()-1].second);
	return;
}

int main()
{
	solve();
	return 0;
}


/*
2 1 2.4 0 3.2
2 2 1.5 1 0.5
*/