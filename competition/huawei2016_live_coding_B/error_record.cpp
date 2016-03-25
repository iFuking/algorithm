#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef struct {
	string name;
	int line;
	int cnt;
	int first;
}RECORD;
vector<RECORD> r;
set<pair<string, int> > s;

const int maxn = 1e3 + 10;
char path[maxn];

bool cmp(const RECORD &r1, const RECORD &r2) {
	if (r1.cnt != r2.cnt) return r1.cnt > r2.cnt;
	return r1.first < r2.first;
}

void solve() {
	char path[maxn]; int line, cnt = 0;
	while (scanf("%s %d", path, &line) && line!=-1) {
		++cnt;

		string p = path;
		int index = p.length();
		for (int i = p.length()-1; i >= 0; --i) {
			if (p[i] == '\\') { index = i+1; break; }
		}
		if (index != p.length()) {
			p = p.substr(index);
		}


		pair<string, int> pp = make_pair(p, line);
		if (s.find(pp) == s.end()) {
			RECORD record;
			record.name = p; record.line = line;
			record.cnt = 1; record.first = cnt;
			r.push_back(record);
			s.insert(pp);
			continue;
		}
		for (int i = 0; i < r.size(); ++i) {
			if (r[i].name==p && r[i].line==line) {
				++r[i].cnt; break;
			}
		}
	}

	sort(r.begin(), r.end(), cmp);
	for (int i = 0; i<8 && i<r.size(); ++i) {
		int index = r[i].name.length()<16 ? 0 : r[i].name.length()-16;
		printf("%s %d %d\n", r[i].name.substr(index).c_str(), r[i].line, r[i].cnt);
	}

	return;
}

int main() {
	solve();
	return 0;
}
