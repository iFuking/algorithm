#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxname = 9;
typedef struct {
	char name[maxname];
	int age, worth;
}PERSON;

const int maxn = 1e5 + 10;
PERSON people[maxn];
const int maxage = 205;
int age_cnt[maxage];
const int maxm = 105;
vector<PERSON> filter;

bool cmp(const PERSON &p1, const PERSON &p2)
{
	if (p1.worth != p2.worth) return p1.worth > p2.worth;
	else if (p1.age != p2.age) return p1.age < p2.age;
	return strcmp(p1.name, p2.name) < 0;
}

void solve()
{
	int N, K; cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		scanf("%s %d %d", people[i].name, &people[i].age, &people[i].worth);
	}
	sort(people, people+N, cmp);

	for (int i = 0; i < N; ++i) {
		++age_cnt[people[i].age];
		if (age_cnt[people[i].age] < maxm) filter.push_back(people[i]);
	}

	for (int i = 1; i <= K; ++i) {
		int M, a_min, a_max; scanf("%d %d %d", &M, &a_min, &a_max);
		int cnt = 0; printf("Case #%d:\n", i);
		for (int j = 0; j<filter.size() && cnt<M; ++j) {
			if (filter[j].age>=a_min && filter[j].age<=a_max) {
				printf("%s %d %d\n", filter[j].name, filter[j].age, filter[j].worth);
				++cnt;
			}
		}
		if (cnt == 0) printf("None\n");
	}
	return;
}

int main()
{
	solve();
	return 0;
}