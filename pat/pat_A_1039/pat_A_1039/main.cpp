#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int namelen = 5;
int N, K; 
map<string, vector<int>> rev_index;

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
			rev_index[stu_name].push_back(course_id);
		}
	}
	return;
}

bool cmp(int n1, int n2) { return n1 < n2; }

void solve()
{
	map<string, vector<int>>::iterator iter = rev_index.begin();
	for ( ; iter != rev_index.end(); ++iter) sort(iter->second.begin(), iter->second.end(), cmp);
	for (int i = 0; i < N; ++i)
	{
		char stu_name[namelen]; scanf("%s", stu_name);
		printf("%s ", stu_name);
		if (rev_index[stu_name].size() == 0) { printf("0\n"); continue; }
		printf("%d ", rev_index[stu_name].size());
		for (int j = 0; j < rev_index[stu_name].size()-1; ++j) printf("%d ", rev_index[stu_name][j]);
		printf("%d\n", rev_index[stu_name][rev_index[stu_name].size()-1]);
	}
	return;
}

int main(int argc, char *argv[])
{
	init();
	solve();
	return 0;
}
