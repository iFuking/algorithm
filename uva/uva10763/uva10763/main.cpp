#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) && n)
	{
		int s, t;
		map<pair<int, int>, int> excs;
		for (int i = 0; i < n; i++)
		{
			cin >> s >> t;
			pair<int, int> exc = make_pair(s, t);
			map<pair<int, int>, int>::iterator iter = excs.find(exc);
			if (iter == excs.end()) excs[exc] = 1;
			else excs[exc]++;
		}

		while (!excs.empty())
		{
			map<pair<int, int>, int>::iterator iter = excs.begin();
			
			pair<int, int> exc = make_pair(iter->first.second, iter->first.first);
			map<pair<int, int>, int>::iterator iterexc = excs.find(exc);
			if (iterexc==excs.end() || (iterexc!=excs.end()&&iter->second!=iterexc->second))
			{
				cout << "NO" << endl;
				break;
			}
			excs.erase(iter);
			excs.erase(iterexc);
		}
		if (excs.empty())
			cout << "YES" << endl;
	}
	return 0;
}