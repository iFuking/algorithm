#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int maxk = 10;
int N, K, M;
int p[maxk];
set<string> user_id;

struct CmpByKey{
	bool operator()(const pair<string, int> &k1, const pair<string, int> &k2) {
		if (k1.first != k2.first) return k1.first < k2.first;
		return k1.second < k2.second;
	}
};
map<pair<string, int>, vector<int>, CmpByKey> records;
bool cmp_value(const int &x, const int &y) { return x > y; }

void solve()
{
	cin >> N >> K >> M;
	for (int i = 0; i < K; ++i) scanf("%d", &p[i]);
	for (int i = 0; i < M; ++i)
	{
		string u_id; int p_id, score;
		cin >> u_id; scanf("%d %d", &p_id, &score);
		user_id.insert(u_id);
		records[make_pair(u_id, p_id)].push_back(score);
	}
	map<pair<string, int>, vector<int>, CmpByKey>::iterator iter = records.begin();
	for ( ; iter != records.end(); ++iter) {
		sort(iter->second.begin(), iter->second.end(), cmp_value);
	}

	return;
}

int main()
{
	solve();
	return 0;
}


/*
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
*/