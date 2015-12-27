#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

const int maxn = 205;

class SameGraph {
public:
	bool visit[maxn];

	void dfs(int vectex, map<int, vector<int> > gp)
	{
		vector<int>::iterator iter = gp[vectex].begin();
		for ( ; iter != gp[vectex].end(); ++iter) {
			if (!visit[*iter]) {
				visit[*iter] = true;
				dfs(*iter, gp);
			}
		}
		return;
	}

    vector<bool> chkSame(int T, vector<int> n, vector<int> m, vector<vector<int> > x1, vector<vector<int> > y1, vector<vector<int> > x2, vector<vector<int> > y2) {
		vector<bool> ans;
		for (int i = 0; i < T; ++i) {
			int N = n[i], E = m[i];
			map<int, vector<int> > gp1, gp2;
			for (int j = 0; j < E; ++j) { gp1[x1[i][j]].push_back(y1[i][j]); gp1[y1[i][j]].push_back(x1[i][j]); }
			for (int j = 0; j < E; ++j) { gp2[x2[i][j]].push_back(y2[i][j]); gp2[y2[i][j]].push_back(x2[i][j]); }

			map<int, int> degree_cnt1, degree_cnt2;
			map<int, vector<int> >::iterator iter1 = gp1.begin();
			for ( ; iter1 != gp1.end(); ++iter1) ++degree_cnt1[iter1->second.size()];
			map<int, vector<int> >::iterator iter2 = gp2.begin();
			for ( ; iter2 != gp2.end(); ++iter2) ++degree_cnt2[iter2->second.size()];

			if (degree_cnt1.size() != degree_cnt2.size()) { ans.push_back(false); continue; }
			map<int, int>::iterator it1 = degree_cnt1.begin(), it2 = degree_cnt2.begin();
			for ( ; it1!=degree_cnt1.end() && it2!=degree_cnt2.end(); ++it1, ++it2) {
				if (*it1 != *it2) { ans.push_back(false); break; }
			}
			if (it1 != degree_cnt1.end()) continue;

			int compo_cnt1 = 0, compo_cnt2 = 0;
			memset(visit, 0, sizeof(visit));
			for (int j = 1; j <= N; ++j) {
				if (!visit[j]) {
					visit[j] = true;
					dfs(j, gp1);
					++compo_cnt1;
				}
			}
			memset(visit, 0, sizeof(visit));
			for (int j = 1; j <= N; ++j) {
				if (!visit[j]) {
					visit[j] = true;
					dfs(j, gp2);
					++compo_cnt2;
				}
			}
			if (compo_cnt1 != compo_cnt2) { ans.push_back(false); continue; }

			ans.push_back(true);
		}
		return ans;
    }
};

int main()
{
	int n[] = {3, 4};
	vector<int> v_n(n, n+sizeof(n)/sizeof(n[0]));
	int m[] = {2, 3};
	vector<int> v_m(m, m+sizeof(m)/sizeof(m[0]));
	
	int x1[][3] = {{1, 2}, {1, 2, 3}};
	vector<vector<int>> v_x1(sizeof(x1)/sizeof(x1[0]), vector<int>(sizeof(x1[0])/sizeof(x1[0][0])));
	for (int i = 0; i < sizeof(x1)/sizeof(x1[0]); ++i) {
		for (int j = 0; j < sizeof(x1[i])/sizeof(x1[i][0]); ++j) {
			v_x1[i][j] = x1[i][j];
		}
	}

	int y1[][3] = {{2, 3}, {2, 3, 4}};
	vector<vector<int>> v_y1(sizeof(y1)/sizeof(y1[0]), vector<int>(sizeof(y1[0])/sizeof(y1[0][0])));
	for (int i = 0; i < sizeof(y1)/sizeof(y1[0]); ++i) {
		for (int j = 0; j < sizeof(y1[i])/sizeof(y1[i][0]); ++j) {
			v_y1[i][j] = y1[i][j];
		}
	}

	int x2[][3] = {{2, 1}, {1, 1, 1}};
	vector<vector<int>> v_x2(sizeof(x2)/sizeof(x2[0]), vector<int>(sizeof(x2[0])/sizeof(x2[0][0])));
	for (int i = 0; i < sizeof(x2)/sizeof(x2[0]); ++i) {
		for (int j = 0; j < sizeof(x2[i])/sizeof(x2[i][0]); ++j) {
			v_x2[i][j] = x2[i][j];
		}
	}

	int y2[][3] = {{1, 3}, {2, 3, 4}};
	vector<vector<int>> v_y2(sizeof(y2)/sizeof(y2[0]), vector<int>(sizeof(y2[0])/sizeof(y2[0][0])));
	for (int i = 0; i < sizeof(y2)/sizeof(y2[0]); ++i) {
		for (int j = 0; j < sizeof(y2[i])/sizeof(y2[i][0]); ++j) {
			v_y2[i][j] = y2[i][j];
		}
	}

	SameGraph sol;
	sol.chkSame(1, v_n, v_m, v_x1, v_y1, v_x2, v_y2);
	return 0;
}