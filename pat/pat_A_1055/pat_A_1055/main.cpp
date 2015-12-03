#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

const int maxname = 9;

typedef struct {
	char name[maxname];
	int age;
	int worth;
}PERSON;

vector<PERSON> people;

bool cmp_age(const PERSON &p1, const PERSON &p2) { return p1.age < p2.age; }

bool cmp(const PERSON &p1, const PERSON &p2)
{
	if (p1.worth != p2.worth) return p1.worth > p2.worth;
	else if (p1.age != p2.age) return p1.age < p2.age;
	return strcmp(p1.name, p2.name) < 0;
}

int b_search(int age)
{
	int head = 0, tail = people.size()-1, mid;
	while (head <= tail) {
		mid = (head+tail) >> 1;
		if (age > people[mid].age) head = mid+1;
		else if (age < people[mid].age) tail = mid-1;
		else break;
	}
	return head;
}

void solve()
{
	int N, K; cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		PERSON p; scanf("%s %d %d", p.name, &p.age, &p.worth);
		people.push_back(p);
	}
	
	sort(people.begin(), people.end(), cmp_age);
	for (int i = 1; i <= K; ++i) {
		int M, a_min, a_max; scanf("%d %d %d", &M, &a_min, &a_max);
		vector<PERSON> ans;
		for (int j = b_search(a_min); j<people.size() && people[j].age<=a_max; ++j) {
			ans.push_back(people[j]);
		}
		sort(ans.begin(), ans.end(), cmp);
		if (ans.size() == 0) { printf("Case #%d:\nNone\n", i); continue; }
		printf("Case #%d:\n", i);
		for (int j = 0; j<ans.size() && j<M; ++j) printf("%s %d %d\n", ans[j].name, ans[j].age, ans[j].worth);
	}
	return;
}

int main()
{
	solve();
	return 0;
}