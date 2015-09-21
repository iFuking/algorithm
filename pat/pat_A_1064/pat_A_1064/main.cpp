#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int a[maxn], tree[maxn];
int N, len = 0;

bool cmp(const int &num1, const int &num2) { return num1 < num2; }

void build_tree(int index)
{
	if (2*index <= N) build_tree(2*index);
	tree[index] = a[len++];
	if (2*index+1 <= N) build_tree(2*index+1);
	return;
}

void solve()
{
	cin >> N;
	for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
	sort(a, a+N, cmp);
	build_tree(1);
	for (int i = 1; i < N; ++i) printf("%d ", tree[i]);
	printf("%d\n", tree[N]);
	return;
}

int main()
{
	solve();
	return 0;
}