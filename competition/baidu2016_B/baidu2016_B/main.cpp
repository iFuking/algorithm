#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <cctype>
using namespace std;

const int maxchar = 1e3 + 10;
char expr[maxchar];
stack<char> st;
vector<char> suffix_exp;
stack<int> sta;

void solve()
{
	scanf("%s", expr);
	for (int i = 0; i < strlen(expr); ++i)
	{
		if (isdigit(expr[i])) suffix_exp.push_back(expr[i]);
		else if (expr[i]=='*' || expr[i]=='/') {
			st.push(expr[i]);
		} else if (expr[i]=='+' || expr[i]=='-') {
			if (st.empty()) st.push(expr[i]);
			else if (st.top()=='*' || st.top()=='/') {
				suffix_exp.push_back(st.top()); st.pop();
				st.push(expr[i]);
			} else st.push(expr[i]);
		}
	}
	while (!st.empty()) { suffix_exp.push_back(st.top()); st.pop(); }

	for (int i = 0; i < suffix_exp.size(); ++i)
	{
		if (isdigit(suffix_exp[i])) sta.push(suffix_exp[i]-'0');
		else {
			int num1 = sta.top(); sta.pop();
			int num2 = sta.top(); sta.pop();
			if (suffix_exp[i] == '+') sta.push(num2+num1);
			else if (suffix_exp[i] == '-') sta.push(num2-num1);
			else if (suffix_exp[i] == '*') sta.push(num2*num1);
			else if (suffix_exp[i] == '/') sta.push(num2/num1);
		}
	}
	printf("%d\n", sta.top());
	return;
}

int main()
{
	solve();
	return 0;
}