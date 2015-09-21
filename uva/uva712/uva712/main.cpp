/*
3
x1 x2 x3
00000111
4
000
010
111
110
3
x3 x1 x2
00010011
4
000
010
111
110
0
*/
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 8;
int n;  // depth
int x_index[maxn];  // for x3, x1, x2 x_index[] = {3, 1, 2}
string leaves;  // terminal nodes


void init()
{
	string xi;  // non-terminal nodes
	memset(x_index, 0, sizeof(x_index));
	for (int i = 0; i < n; i++) 
	{ cin >> xi; x_index[i] = xi[1]-'0'; }
	cin >> leaves;
	return;
}

void solve()
{
	int m;  // the number of VVAs
	cin >> m;
	string ans;  // final results

	while (m--)
	{
		string xi_sequence;  // x1, x2, .. , xn value
		cin >> xi_sequence;
		int leaves_index = 1;  // range (0, 2^n-1)
		for (int i = 0; i < n; i++)
		{   // for root n, its left node is 2*n, right node is 2*n+1
			if (xi_sequence[x_index[i]-1] == '1') leaves_index = 2*leaves_index+1;
			else leaves_index = 2*leaves_index;
		}
		leaves_index -= pow(2.0, n);
		ans += leaves[leaves_index];
	}
	cout << ans << endl;
	return;
}

int main()
{
	while (cin >> n && n)
	{
		init();
		solve();
	}
	return 0;
}