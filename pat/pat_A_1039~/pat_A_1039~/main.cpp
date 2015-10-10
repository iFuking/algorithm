#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 26*26*26*10 + 10;
const int namelen = 5;
int N, K;
vector<int> stu_id[maxn];

int hash_name(char *name)
{
	return (name[0]-'A')*26*26*10 + 
		(name[1]-'A')*26*10 + 
		(name[2]-'A')*10 + (name[3]-'0');
}

void init()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; ++i)
	{
		int course_id, stu_nums;
		scanf("%d %d", &course_id, &stu_nums);
		for (int j = 0; j < stu_nums; ++j)
		{
			char stu_name[namelen]; scanf("%s", stu_name);
			stu_id[hash_name(stu_name)].push_back(course_id);
		}
	}
	return;
}

bool cmp(int n1, int n2) { return n1 < n2; }

void solve()
{
	for (int i = 0; i < N; ++i)
	{
		char stu_name[namelen]; scanf("%s", stu_name);
		printf("%s ", stu_name);
		int id = hash_name(stu_name);
		sort(stu_id[id].begin(), stu_id[id].end(), cmp);
		if (stu_id[id].size() == 0) { printf("0\n"); continue; }
		printf("%d ", stu_id[id].size());
		for (int j = 0; j < stu_id[id].size()-1; ++j) printf("%d ", stu_id[id][j]);
		printf("%d\n", stu_id[id][stu_id[id].size()-1]);
	}
	return;
}

int main(int argc, char *argv[])
{
	init();
	solve();
	return 0;
}