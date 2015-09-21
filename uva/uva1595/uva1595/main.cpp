#include <iostream>
#include <set>
using namespace std;

int main()
{
	int cases;
	cin >> cases;
	
	while (cases--)
	{
		int n;
		cin >> n;
		set<pair<int, int>> pixelset;
		int xleftmost = 10010, xrightmost = -10010;
		int x, y;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			if (x < xleftmost) xleftmost = x;
			if (x > xrightmost) xrightmost = x;
			pixelset.insert(make_pair(x, y));
		}
		float syx = (xleftmost+xrightmost)/2.0;
		set<pair<int, int>>::iterator iter = pixelset.begin();
		while (iter != pixelset.end())
		{
			pair<int, int> pixel = make_pair((int)(2*syx-iter->first), iter->second);
			if (!pixelset.count(pixel))
			{
				cout << "NO" << endl;
				break;
			}
			iter++;
		}
		if (iter == pixelset.end())
			cout << "YES" << endl;
	}
	return 0;
}