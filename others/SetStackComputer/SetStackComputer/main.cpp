#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

typedef set<int> Set;
map<Set, int> IDcache;  // set to id
vector<Set> Setcache;   // Set sets, also known as set<Set>

int ID(Set x)
{
	map<Set, int>::iterator iter = IDcache.find(x);
	if (iter != IDcache.end()) return IDcache[x];
	Setcache.push_back(x);
	return Setcache.size()-1;
}

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

int main()
{
	stack<int> st;
	int Op_nums;
	cin >> Op_nums;

	while (Op_nums--)
	{
		string op;
		cin >> op;

		if (op[0] == 'P') st.push(ID(Set()));
		else if (op[0] == 'D') st.push(st.top());
		else
		{
			Set x1 = Setcache[st.top()]; st.pop();
			Set x2 = Setcache[st.top()]; st.pop();
			Set x;
			if (op[0] == 'U') set_union(ALL(x1), ALL(x2), INS(x));
			if (op[0] == 'I') set_intersection(ALL(x1), ALL(x2), INS(x));
			if (op[0] == 'A') { x = x2; x.insert(ID(x1)); }
			st.push(ID(x));
		}
		cout << Setcache[st.top()].size() << endl;
	}
	return 0;
}