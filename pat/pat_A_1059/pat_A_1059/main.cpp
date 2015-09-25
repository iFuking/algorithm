#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	int fac, num;
}Fac;
vector<Fac> ans;

void solve()
{
	int N, tmp; cin >> N;
	if (N == 1) { printf("1=1\n"); return; }
	tmp = N;
	for (int i = 2; tmp > 1 && i*i<=N; ++i)
	{
		Fac f; f.fac = 0; f.num = 0;
		while (tmp % i == 0) { f.fac = i; ++f.num; tmp /= i; }
		if (f.fac > 0) ans.push_back(f);
	}
	if (tmp > 1) {
		Fac f; f.fac = tmp; f.num = 1;
		ans.push_back(f);
	}

	printf("%d=", N);
	for (int i = 0; i < ans.size()-1; ++i) {
		if (ans[i].num > 1) printf("%d^%d*", ans[i].fac, ans[i].num);
		else printf("%d*", ans[i].fac);
	}
	if (ans[ans.size()-1].num > 1) printf("%d^%d\n", ans[ans.size()-1].fac, ans[ans.size()-1].num);
	else printf("%d\n", ans[ans.size()-1].fac);
	return;
}

int main()
{
	solve();
	return 0;
}