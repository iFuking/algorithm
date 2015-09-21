#include <iostream>
#include <queue>
#include <set>
using namespace std;

const int FAC[] = {2, 3, 5};
const int NUM = 1500;

int main()
{
	priority_queue<__int64, vector<__int64>, greater<__int64>> pq;
	set<__int64> dup;
	int cnt = 1;
	
	pq.push(1);
	dup.insert(1);
	while (true)
	{
		__int64 x = pq.top();
		pq.pop();
		if (cnt == NUM)
		{
			cout << x << endl;
			break;
		}

		for (int i = 0; i < 3; i++)
		{
			__int64 facx = x*FAC[i];
			if (!dup.count(facx))
			{
				pq.push(facx);
				dup.insert(facx);
			}
		}
		cnt++;
	}
	return 0;
}