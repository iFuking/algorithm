/*
5
5 7 -1 6 -1 -1 3 -1 -1
8 2 9 -1 -1 6 5 -1 -1 12 -1 -1 3 7 -1 -1 -1
-1
*/
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1010;
int sum[maxn];

void build(int pos)
{
	int v; cin >> v;
	if (v == -1) return;
	sum[pos] += v;
	build(pos - 1);
	build(pos + 1);
	return;
}

bool init()
{
	int v; cin >> v;
	if (v == -1) return false;
	int pos = maxn>>1;
	sum[pos] = v;
	build(pos - 1);
	build(pos + 1);
	return true;
}

int main()
{
	int items; cin >> items;
	for (int i = 1; i <= items; i++)
	{
		memset(sum, 0, sizeof(sum));
		if (init()) cout << "Case " << i << ":" << endl;
		int p = 0;
		while (!sum[p]) p++;
		while (sum[p]) cout << sum[p++] << " ";
		cout << endl;
	}
	return 0;
}