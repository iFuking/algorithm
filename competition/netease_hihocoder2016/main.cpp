#include <iostream>
#include <cstdio>
#include <vector>
#include <cctype>
#include <set>
using namespace std;

const int digit[][7] = {
	{1, 2, 3, 0, 5, 6, 7},
	{0, 0, 3, 0, 0, 6, 0},
	{1, 0, 3, 4, 5, 0, 7},
	{1, 0, 3, 4, 0, 6, 7},
	{0, 2, 3, 4, 0, 6, 0},
	{1, 2, 0, 4, 0, 6, 7},
	{1, 2, 0, 4, 5, 6, 7},
	{1, 0, 3, 0, 0, 6, 0},
	{1, 2, 3, 4, 5, 6, 7},
	{1, 2, 3, 4, 0, 6, 7}
};

void dfs(vector<vector<int> > &p, int k, vector<int> &num, int &sum) {
	for (int i = p[k].size()-1; i >= 0; --i) {
		if (p[k][i] < num[k]) {
			int tmp = i+1;
			for (int j = k+1; j < p.size(); ++j) {
				tmp *= p[j].size();
			}
			sum += tmp;
			break;
		} else if (p[k][i] == num[k]) {
			dfs(p, k+1, num, sum);
		}
	}
	return;
}

void solve() {
	int S; cin >> S;

	vector<set<int> > d;
	for (int i = 0; i < sizeof(digit)/sizeof(digit[0]); ++i) {
		set<int> s;
		for (int j = 0; j < sizeof(digit[i])/sizeof(digit[i][0]); ++j) {
			if (digit[i][j] > 0) {
				s.insert(digit[i][j]);
			}
		}
		d.push_back(s);
	}

	while (S--) {
		int K, N; scanf("%d %d", &K, &N);
		getchar();

		vector<vector<int> > vv;
		for (int k = 0; k < K; ++k) {
			char ch; vector<int> v;
			while ((ch = getchar()) != '\n') {
				if (isdigit(ch)) {
					v.push_back(ch-'0');
				}
			}
			vv.push_back(v);
		}

		vector<vector<int> > p;
		for (int k = 0; k < K; ++k) {
			vector<int> v;
			for (int i = 0; i < d.size(); ++i) {
				bool flag = false;
				for (int j = 0; j < vv[k].size(); ++j) {
					if (d[i].find(vv[k][j]) == d[i].end()) {
						flag = true; break;
					}
				}
				if (!flag) v.push_back(i);
			}
			p.push_back(v);
		}

		vector<int> num; int n = N;
		while (n) {
			num.push_back(n%10);
			n /= 10;
		}

		while (num.size() < K) num.push_back(0);
		for (int i = 0; i < num.size()/2; ++i) {
			swap(num[i], num[num.size()-1-i]);
		}

		int sum = 0;
		dfs(p, 0, num, sum);
		printf("%d\n", sum);
	}
	return;
}

int main() {
	solve();
	return 0;
}

