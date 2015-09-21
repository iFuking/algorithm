#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	queue<int> from, to;
	int n, in;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		from.push(i);
		cin >> in;
		to.push(in);
	}
	stack<int> st;

	while (!to.empty())
	{
		if (from.empty() && to.front()!=st.top())
		{
			cout << "NO" << endl;
			return 0;
		}
		else if (!from.empty() && from.front()==to.front())
		{
			from.pop();
			to.pop();
		}
		else if (!st.empty() && to.front()==st.top())
		{
			to.pop();
			st.pop();
		}
		else 
		{
			st.push(from.front());
			from.pop();
		}
	}	cout << "YES" << endl;

	return 0;
}