#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, P;
vector<int> sol;
vector<vector<int>> sols;

void dfs(int sum, int k, int f)
{
	if (sum>N || k>K) return;
	if (sum==N && k==K) { sols.push_back(sol); return; }
	for (int fac = pow(N, 1.0/P); fac >= 1; --fac) {
		if (f >= fac) {
			sol.push_back(fac);
			sum += pow(fac, P*1.0);
			dfs(sum, k+1, fac);
			sol.pop_back();
			sum -= pow(fac, P*1.0);
		}
	}
	return;
}

bool cmp(const vector<int> &v1, const vector<int> &v2)
{
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < v1.size(); ++i) sum1 += v1[i];
	for (int i = 0; i < v2.size(); ++i) sum2 += v2[i];
	if (sum1 != sum2) return sum1 > sum2;
	for (int i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i]) return v1[i] > v2[i];
	}
	return false;
}

void solve()
{
	cin >> N >> K >> P;
	dfs(0, 0, pow(N, 1.0/P));
	if (sols.size() == 0) { printf("Impossible\n"); return; }
	sort(sols.begin(), sols.end(), cmp);
	printf("%d = ", N);
	for (int i = 0; i < sols[0].size()-1; ++i) printf("%d^%d + ", sols[0][i], P);
	printf("%d^%d", sols[0][sols[0].size()-1], P);
	return;
}

int main()
{
	solve();
	return 0;
}