#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxk = 6;
int pro[maxk];

typedef struct {
	int rank;
	string id;
	int total_score;
	int valid_nums;
	map<int, int> pro_score;
}RESULT;

bool cmp(const RESULT &r1, const RESULT &r2)
{
	if (r1.total_score != r2.total_score) return r1.total_score > r2.total_score;
	else if (r1.valid_nums != r2.valid_nums) return r1.valid_nums > r2.valid_nums;
	return r1.id < r2.id;
}

void solve()
{
	int N, K, M; cin >> N >> K >> M;
	for (int i = 0; i < K; ++i) scanf("%d", &pro[i]);
	map<string, map<int, int>> record;
	for (int i = 0; i < M; ++i) {
		char id[maxk]; int pro_id, score; scanf("%s %d %d", id, &pro_id, &score);
		if (score > record[id][pro_id]) record[id][pro_id] = score;
	}
	
	vector<RESULT> res;
	map<string, map<int, int>>::iterator iter = record.begin();
	for ( ; iter != record.end(); ++iter) {
		RESULT r; r.id = iter->first;
		r.total_score = 0; r.valid_nums = 0;
		map<int, int>::iterator it = iter->second.begin();
		for ( ; it != iter->second.end(); ++it) {
			r.total_score += it->second;
			if (pro[it->first-1] == it->second) ++r.valid_nums;
		}
		r.pro_score = iter->second;
		res.push_back(r);
	}
	sort(res.begin(), res.end(), cmp);

	res[0].rank = 1;
	printf("%d %s %d ", res[0].rank, res[0].id.c_str(), res[0].total_score);
	for (int i = 1; i < K; ++i) {
		if (record[res[0].id].find(i)!=record[res[0].id].end()) printf("%d ", res[0].pro_score[i]);
		else printf("- ");
	}
	if (record[res[0].id].find(K)!=record[res[0].id].end()) printf("%d\n", res[0].pro_score[4]);
	else printf("-\n");

	for (int i = 1; i < res.size(); ++i) {
		if (res[i].total_score == 0) break;
		if (res[i].total_score == res[i-1].total_score) res[i].rank = res[i-1].rank;
		else res[i].rank = i+1;
		printf("%d %s %d ", res[i].rank, res[i].id.c_str(), res[i].total_score);
		for (int j = 1; j < 4; ++j) {
			if (record[res[i].id].find(j)!=record[res[i].id].end()) printf("%d ", res[i].pro_score[j]);
			else printf("- ");
		}
		if (record[res[i].id].find(K)!=record[res[i].id].end()) printf("%d\n", res[i].pro_score[4]);
		else printf("-\n");
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