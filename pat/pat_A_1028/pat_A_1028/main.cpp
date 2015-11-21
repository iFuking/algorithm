#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxch = 9;

typedef struct {
	string id;
	string name;
	int grade;
}STU;

bool cmp_id(const STU &s1, const STU &s2) { return s1.id < s2.id; }
bool cmp_name(const STU &s1, const STU &s2)
{
	if (s1.name != s2.name) return s1.name < s2.name;
	return s1.id < s2.id;
}
bool cmp_grade(const STU &s1, const STU &s2)
{
	if (s1.grade != s2.grade) return s1.grade < s2.grade;
	return s1.id < s2.id;
}

void solve()
{
	int N, C; cin >> N >> C;
	vector<STU> stu;
	for (int i = 0; i < N; ++i) {
		char id[maxch], name[maxch];
		STU s; scanf("%s %s %d", id, name, &s.grade);
		s.id = id; s.name = name;
		stu.push_back(s);
	}

	if (C == 1) sort(stu.begin(), stu.end(), cmp_id);
	else if (C == 2) sort(stu.begin(), stu.end(), cmp_name);
	else if (C == 3) sort(stu.begin(), stu.end(), cmp_grade);
	for (int i = 0; i < stu.size(); ++i) {
		printf("%s %s %d\n", stu[i].id.c_str(), stu[i].name.c_str(), stu[i].grade);
	}
	return;
}

int main()
{
	solve();
	return 0;
}