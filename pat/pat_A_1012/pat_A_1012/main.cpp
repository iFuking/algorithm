#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int maxch = 7;
const char course_name[] = {'C', 'M', 'E', 'A'};
const int course_prioruty[] = {3, 2, 1, 4};

typedef struct {
	char name;
	int grade;
	int rank;
	int priority;
}CRS;

typedef struct {
	char id[maxch];
	vector<CRS> course;
}STU;

bool cmp0(const STU &s1, const STU &s2) { return s1.course[0].grade > s2.course[0].grade; }
bool cmp1(const STU &s1, const STU &s2) { return s1.course[1].grade > s2.course[1].grade; }
bool cmp2(const STU &s1, const STU &s2) { return s1.course[2].grade > s2.course[2].grade; }
bool cmp3(const STU &s1, const STU &s2) { return s1.course[3].grade > s2.course[3].grade; }

bool cmp(const CRS &c1, const CRS &c2)
{
	if (c1.rank != c2.rank) return c1.rank < c2.rank;
	return c1.priority > c2.priority;
}

void course_rank(vector<STU> &stu, int course_id)
{
	stu[0].course[course_id].rank = 1;
	for (int i = 1; i < stu.size(); ++i) {
		if (stu[i].course[course_id].grade == stu[0].course[course_id].grade) {
			stu[i].course[course_id].rank = stu[0].course[course_id].rank;
		} else stu[i].course[course_id].rank = i+1;
	}
	return;
}

void solve()
{
	int N, M; cin >> N >> M;
	vector<STU> stu;
	for (int i = 0; i < N; ++i) {
		STU s; scanf("%s", s.id);
		for (int j = 0; j < 3; ++j) {
			CRS c; c.name = course_name[j];
			c.priority = course_prioruty[j];
			scanf("%d", &c.grade);
			s.course.push_back(c);
		}
		CRS c; c.name = course_name[3];
		c.priority = course_prioruty[3];
		c.grade = 0;
		for (int j = 0; j < 3; ++j) c.grade += s.course[j].grade;
		c.grade /= 3;
		s.course.push_back(c);
		stu.push_back(s);
	}

	sort(stu.begin(), stu.end(), cmp0); course_rank(stu, 0);
	sort(stu.begin(), stu.end(), cmp1); course_rank(stu, 1);
	sort(stu.begin(), stu.end(), cmp2); course_rank(stu, 2);
	sort(stu.begin(), stu.end(), cmp3); course_rank(stu, 3);

	map<string, STU> students;
	for (int i = 0; i < N; ++i) {
		sort(stu[i].course.begin(), stu[i].course.end(), cmp);
		students[stu[i].id] = stu[i];
	}

	map<string, STU>::iterator iter;
	for (int i = 0; i < M; ++i) {
		char id[maxch]; scanf("%s", id);
		iter = students.find(id);
		if (iter != students.end()) {
			printf("%d %c\n", iter->second.course[0].rank, iter->second.course[0].name);
		} else printf("N/A\n");
	}
	return;
}

int main()
{
	solve();
	return 0;
}