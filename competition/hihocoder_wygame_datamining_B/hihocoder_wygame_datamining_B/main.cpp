#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef struct { int cid; string name; int ctype; }Channel;
typedef struct { int pid; string name; int cid;}Player;
typedef struct { int id; int pid; int cash; }Prepaid;
vector<Channel> cha;
vector<Player> pla;
vector<Prepaid> pre;
typedef struct { int pid; int ctype; }PlaCha_join;
vector<PlaCha_join> pla_cha;
typedef struct { int pid; int ctype; int cash; }PlaChaPre_join;
vector<PlaChaPre_join> pla_cha_pre;

struct Cmp {
	bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
		if (p1.second != p2.second) return p1.second > p2.second;
		return p1.first < p2.first;
	}
};
map<int, pair<int, int>> result;

void input()
{
	int t_nums = 3;
	while (t_nums--)
	{
		string tname; int m; cin >> tname >> m;
		string ig1, ig2, ig3; cin >> ig1 >> ig2 >> ig3;
		if (tname == "channels") {
			Channel c;
			for (int i = 0; i < m; ++i) {
				cin >> c.cid >> c.name >> c.ctype;
				cha.push_back(c);
			}
		} else if (tname == "players") {
			Player p;
			for (int i = 0; i < m; ++i) {
				cin >> p.pid >> p.name >> p.cid;
				pla.push_back(p);
			}
		} else if (tname == "prepaids") {
			Prepaid p;
			for (int i = 0; i < m; ++i) {
				cin >> p.id >> p.pid >> p.cash;
				pre.push_back(p);
			}
		}
	}
	return;
}

void first_select()
{
	for (int i = 0; i < pla.size(); ++i) {
		PlaCha_join pc; bool flag = false;
		for (int j = 0; j < cha.size(); ++j) {
			if (pla[i].cid == cha[j].cid) {
				pc.pid = pla[i].pid; pc.ctype = cha[j].ctype;
				flag = true; break;
			}
		}
		if (!flag) {
			pc.pid = pla[i].pid; pc.ctype = -1;
		}
		pla_cha.push_back(pc);
	}
	return;
}

void second_select()
{
	for (int i = 0; i < pla_cha.size(); ++i) {
		PlaChaPre_join pcp;
		for (int j = 0; j < pre.size(); ++j) {
			if (pla_cha[i].pid == pre[j].pid) {
				pcp.pid = pla_cha[i].pid;
				pcp.ctype = pla_cha[i].ctype;
				pcp.cash = pre[j].cash;
				pla_cha_pre.push_back(pcp);
				break;
			}
		}
	}
	return;
}

void group_ctype()
{
	for (int i = 0; i < pla_cha_pre.size(); ++i) {
		result[pla_cha_pre[i].ctype].first++;
		result[pla_cha_pre[i].ctype].second += pla_cha_pre[i].cash;
	}
	return;
}

void solve()
{
	input();
	first_select();
	second_select();
	group_ctype();
	return;
}

int main()
{
	solve();
	return 0;
}