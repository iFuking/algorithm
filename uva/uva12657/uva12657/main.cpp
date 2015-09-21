#include <iostream>
#include <list>
using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		list<int> l;
		for (int i = 1; i <= n; i++)
			l.push_back(i);
		int op, x, y;
		for (int i = 0; i < m; i++)
		{
			cin >> op;
			if (op <= 3) cin >> x >> y;	
			list<int>::iterator iter = l.begin();
			if (op == 1) {
				while (iter != l.end())
				{
					if (*iter == x) iter = l.erase(iter);
					else if (*iter == y) l.insert(iter++, x);
					else iter++;
				}
			} else if (op == 2) {
				while (iter != l.end())
				{
					if (*iter == x) iter = l.erase(iter);
					else if (*iter == y) { iter++; l.insert(iter, x); continue; }
					else iter++;
				}
			} else if (op == 3) {
				list<int>::iterator it;
				int tmp, find = 0;
				for ( ;iter != l.end(); iter++)
				{
					if (*iter == x || *iter == y) 	
					{
						find++;
						if (find == 1) it = iter;
						else if (find == 2) { tmp = *iter; *iter = *it; *it = tmp; }
					}
				}
			} else if (op == 4) {
				l.reverse();
			}
		}

		list<int>::iterator iter = l.begin();
		__int64 sum = 0;
		for (int i = 0; iter != l.end(); i++, iter++)
		{
			if (i%2 == 0) sum += *iter;
		}
		cout << sum << endl;
	}

	/*list<int> l;
	for (int i = 0; i < 10; i++)
		l.push_back(i);
	list<int>::iterator iter = l.begin();
	for ( ; iter != l.end(); )
	{
		if (*iter == 4) iter = l.erase(iter);
		else ++iter;
	}
	l.reverse();*/
	return 0;
}