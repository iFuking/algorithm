#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 1050000;
bool st[maxn];

int main()
{
	int D, I;
	while (cin >> D >> I)
	{
		if (D == 1) { cout << "1" << endl; continue; }
		memset(st, 0, sizeof(st));
		int k;
		for (int i = 1; i <= I; i++)
		{
			k = 1;
			while (true)
			{
				k = st[k] ? 2*k+1 : 2*k;
				st[k/2] = !st[k/2];
				if (k > pow(2.0, D-1)-1) break;
			}
		}
		cout << k << endl;
	}
	return 0;
}
