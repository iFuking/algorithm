#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

const int l[] = {10, 6, 5, 4};
const int c[] = {10, 0, 0, 0};
map<vector<int>, int> m;

void bfs() {
	vector<int> l0, s0;
	for (int i = 0; i < sizeof(c)/sizeof(c[0]); ++i) {
		l0.push_back(l[i]);
		s0.push_back(c[i]);
	}

	vector<int> p(4);
	for (int i = 0; i < 4; ++i) {
		scanf("%d", &p[i]);
	}
	if (p == s0) {
		printf("0\n");
		return;
	}

	queue<vector<int> > q;
	q.push(s0); m[s0] = 1;
	
	int head = 0, tail = 1, tmp = tail, step = 0;
	while (!q.empty()) {
		while (head < tail) {
			vector<int> v = q.front();
			q.pop(); ++head;
			if (m[v] == 2) continue;
			m[v] = 2;

			for (int i = 0; i < v.size(); ++i) {
				if (v[i] > 0) {
					for (int j = 0; j < v.size(); ++j) {
						if (j!=i && v[j]<l0[j]) {
							vector<int> s = v;
							if (s[i] >= (l0[j]-s[j])) {
								s[i] -= (l0[j]-s[j]);
								s[j] = l0[j];
							} else {
								s[j] += s[i];
								s[i] = 0;
							}

							if (!m[s]) {
								q.push(s);
								m[s] = 1;
								++tmp;
							}
						}
					}
				}
			}
		}
		++step;
		tail = tmp;

		if (m.find(p) != m.end()) {
			printf("%d\n", step);
			return;
		}
	}
	printf("-1\n");

	// int cnt = 0;
	// map<vector<int>, int>::iterator iter = m.begin();
	// for ( ; iter != m.end(); ++iter) {
	// 	vector<int>::const_iterator ite = iter->first.begin();
	// 	for ( ; ite != iter->first.end(); ++ite) {
	// 		printf("%d ", *ite);
	// 	}
	// 	printf("\n");
	// 	++cnt;
	// }
	// printf("Total: %d\n", cnt);
	return;
}

void solve() {
	bfs();
	return;
}

int main() {
	solve();
	return 0;
}