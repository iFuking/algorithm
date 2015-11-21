#include <iostream>
#include <vector>
using namespace std;

void solve()
{
	vector<long long> v1, v2;
	int N; cin >> N;
	for (int i = 0; i < N; ++i) {
		long long num; scanf("%lld", &num);
		v1.push_back(num);
	}
	v1.push_back(0x7fffffffffffffff);

	int M; cin >> M;
	for (int i = 0; i < M; ++i) {
		long long num; scanf("%lld", &num);
		v2.push_back(num);
	}
	v2.push_back(0x7fffffffffffffff);

	int k = 0, j = 0, cnt = 0;
	int median = (N+M-1)/2;
	while (cnt < median) {
		if (v1[k] < v2[j]) ++k;
		else ++j;
		++cnt;
	}
	if (v1[k] < v2[j]) printf("%d\n", v1[k]);
	else printf("%d\n", v2[j]);
	return;
}

int main()
{
	solve();
	return 0;
}