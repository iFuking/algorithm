#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 11;

typedef struct {
	char name[maxn];
	char id[maxn];
	int grade;
}STU;

bool cmp(const STU &s1, const STU &s2) { return s1.grade > s2.grade; }

void solve()
{
	int N; cin >> N;

	vector<STU> male, female;
	for (int i = 0; i < N; ++i) {
		STU s; char gender;
		scanf("%s %c %s %d", s.name, &gender, s.id, &s.grade);
		if (gender == 'M') male.push_back(s);
		else female.push_back(s);
	}
	sort(male.begin(), male.end(), cmp);
	sort(female.begin(), female.end(), cmp);

	bool absent = false;
	if (male.size()==0 || female.size()==0) absent = true;
	
	if (female.size() == 0) printf("Absent\n");
	else printf("%s %s\n", female[0].name, female[0].id);
	if (male.size() == 0) printf("Absent\n");
	else printf("%s %s\n", male[male.size()-1].name, male[male.size()-1].id);
	if (!absent) printf("%d\n", female[0].grade-male[male.size()-1].grade);
	else printf("NA\n");
	return;
}

int main()
{
	solve();
	return 0;
}