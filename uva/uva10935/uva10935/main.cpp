#include <iostream>
#include <cstdio>
#include <list>
using namespace std;

int main()
{
	int n;

	while (scanf("%d", &n) && n)
	{
		if (n == 1)
		{
			cout << "Discarded cards:" << endl;
			cout << "Remaining card: 1" << endl;
			continue;
		}
		cout << "Discarded cards:";
		list<int> l;
		for (int i = 1; i <= n; i++)
			l.push_back(i);

		while (l.size() > 2)
		{
			cout << " " << l.front() << ",";
			l.pop_front();
			l.push_back(l.front());
			l.pop_front();
		}
		cout << " " << l.front() << endl;
		l.pop_front();
		cout << "Remaining card: " << l.front() << endl;
	}
	return 0;
}