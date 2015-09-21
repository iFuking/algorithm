#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int index;
	int priority;
}Node;

bool operator<(const Node &a, const Node &b)
{
	if (a.priority != b.priority)
		return a.priority > b.priority;
	return a.index < b.index;
}

int main()
{
	int cases;
	cin >> cases;

	int n, m;
	while (cases--)
	{
		cin >> n >> m;
		queue<Node> printer;
		vector<Node> max;

		Node item;
		int priority;
		for (int i = 0; i < n; i++)
		{
			cin >> priority;
			item.index = i;
			item.priority = priority;
			printer.push(item);
			max.push_back(item);
		}
		sort(max.begin(), max.end());

		int cnt = 0;
		vector<Node>::iterator iter = max.begin();
		while (!printer.empty())
		{
			int findex = printer.front().index;
			int fpriority = printer.front().priority;	
			if (iter->priority > fpriority)
			{
				printer.push(printer.front());
				printer.pop();
			} else {
				cnt++;
				if (findex == m)
				{
					cout << cnt << endl;
					break;
				}
				printer.pop();
				iter++;
			}
		}
	}
	return 0;
}