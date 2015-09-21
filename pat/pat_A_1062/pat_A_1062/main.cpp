#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int max_id = 9;
typedef struct {
	char id[max_id];
	int vir, tal;
}Man;
int N, L, H;
vector<Man> sage, nobleman, fool, small;

bool cmp(const Man &m1, const Man &m2)
{
	if (m1.vir+m1.tal != m2.vir+m2.tal) return m1.vir+m1.tal > m2.vir+m2.tal;
	else if (m1.vir != m2.vir) return m1.vir > m2.vir;
	return strcmp(m1.id, m2.id) < 0;
}

void solve()
{
	cin >> N >> L >> H;
	for (int i = 0; i < N; ++i) {
		Man m; scanf("%s %d %d", m.id, &m.vir, &m.tal);
		if (m.vir<L || m.tal<L) continue;
		else if (m.vir>=H && m.tal>=H) sage.push_back(m);
		else if (m.tal<H && m.vir>=H) nobleman.push_back(m);
		else if (m.vir<H && m.tal<H && m.vir>=m.tal) fool.push_back(m);
		else small.push_back(m);
	}
	sort(sage.begin(), sage.end(), cmp);
	sort(nobleman.begin(), nobleman.end(), cmp);
	sort(fool.begin(), fool.end(), cmp);
	sort(small.begin(), small.end(), cmp);
	printf("%d\n", sage.size()+nobleman.size()+fool.size()+small.size());
	for (int i = 0; i < sage.size(); ++i) printf("%s %d %d\n", sage[i].id, sage[i].vir, sage[i].tal);
	for (int i = 0; i < nobleman.size(); ++i) printf("%s %d %d\n", nobleman[i].id, nobleman[i].vir, nobleman[i].tal);
	for (int i = 0; i < fool.size(); ++i) printf("%s %d %d\n", fool[i].id, fool[i].vir, fool[i].tal);
	for (int i = 0; i < small.size(); ++i) printf("%s %d %d\n", small[i].id, small[i].vir, small[i].tal);
	return;
}

int main()
{
	solve();
	return 0;
}