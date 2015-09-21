#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int cases;
	cin >> cases;

	priority_queue<int> pq;
	while (cases--)
	{
		char ch;
		int w;
		cin >> ch;

		if (ch == 'A') {
			cin >> w;
			pq.push(w);
		} else if (ch == 'T') {
			cout << pq.top() << endl;
			pq.pop();
		}
	}
	return 0;
}