#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxd = 15;
const int maxn = 105;
const int maxk = 305;

typedef struct {
	char id[maxd];
	int score;
	int final_rank;
	int location_number;
	int local_rank;
}STU;

typedef struct {
	char id[maxd];
	int score;
	int rank;
}SCORE;

bool cmp_score(const SCORE &s1, const SCORE &s2)
{
	if (s1.score != s2.score) return s1.score > s2.score;
	return strcmp(s1.id, s2.id) < 0;
}

bool cmp_stu(const STU &s1, const STU &s2)
{
	if (s1.score != s2.score) return s1.score > s2.score;
	return strcmp(s1.id, s2.id) < 0;
}

void solve()
{
	int N; cin >> N;
	vector<STU> stu;
	for (int i = 1; i <= N; ++i) {
		int K; scanf("%d", &K);
		vector<SCORE> sco;
		for (int j = 0; j < K; ++j) {
			SCORE s; scanf("%s %d", s.id, &s.score);
			sco.push_back(s);
		}
		sort(sco.begin(), sco.end(), cmp_score);
		sco[0].rank = 1;
		for (int j = 1; j < K; ++j) {
			if (sco[j].score == sco[j-1].score) sco[j].rank = sco[j-1].rank;
			else sco[j].rank = j+1;
		}

		for (int j = 0; j < K; ++j) {
			STU s; strcpy(s.id, sco[j].id); s.score = sco[j].score;
			s.location_number = i; s.local_rank = sco[j].rank;
			stu.push_back(s);
		}
	}

	sort(stu.begin(), stu.end(), cmp_stu);
	stu[0].final_rank = 1;
	for (int i = 1; i < stu.size(); ++i) {
		if (stu[i].score == stu[i-1].score) stu[i].final_rank = stu[i-1].final_rank;
		else stu[i].final_rank = i+1;
	}

	printf("%d\n", stu.size());
	for (int i = 0; i < stu.size(); ++i) {
		printf("%s %d %d %d\n", stu[i].id, stu[i].final_rank, stu[i].location_number, stu[i].local_rank);
	}
	return;
}

int main()
{
	solve();
	return 0;
}


/*
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
*/