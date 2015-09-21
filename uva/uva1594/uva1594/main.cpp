#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 15;

int main()
{
	int cases;
	cin >> cases;

	int n, a[maxn];
	while (cases--)
	{
		cin >> n;
		int sum = 0, a0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}

		int loops = 1000;
		while (loops--)
		{
			if (sum == 0)
			{
				cout << "ZERO" << endl;
				break;
			}
			a0 = a[0];
			sum = 0;
			for (int i = 0; i < n-1; i++)
				sum += (a[i]=abs(a[i+1]-a[i]));
			sum += (a[n-1]=abs(a0-a[n-1]));
		}
		if (sum)
			cout << "LOOP" << endl;
	}
	return 0;
}