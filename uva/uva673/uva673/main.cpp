/*
3
([])
(([()])))
([()[]()])()
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool match(char ch1, char ch2)
{
	if (ch1=='(' && ch2==')') return true;
	else if (ch1=='[' && ch2==']') return true;
	return false;
}

int main()
{
	stack<char> st;
	int t; cin >> t;
	while (t--)
	{
		string str; cin >> str;
		if (str == "") { cout << "No" << endl; continue; }
		bool flag = false;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i]=='(' || str[i]=='[') st.push(str[i]);
			else {
				if (st.empty())  { cout << "No" << endl; flag = true; } 
				else if (!match(st.top(),str[i])) { cout << "No" << endl; flag = true; }
				else st.pop();
			}
		}
		if (st.empty() && !flag) cout << "Yes" << endl;
		else if (!flag) cout << "No" << endl;
	}
	return 0;
}