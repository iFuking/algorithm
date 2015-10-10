#include <iostream>
#include <string>
#include <cctype>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        string str = "";
		for (int i = 0; i < s.length(); ++i) {
			if (!isspace(s[i])) str += s[i];
		}

		vector<char> suf_exp;
		stack<char> st;
		for (int i = 0; i < str.length(); ++i) {
			if (str[i]>='0' && str[i]<='9') { suf_exp.push_back(str[i]); continue; }
			if (str[i]=='*' || str[i]=='/') {
				while (!st.empty() && (st.top()=='*'||st.top()=='/')) { suf_exp.push_back(st.top()); st.pop(); }
				st.push(str[i]);
			} else {
				while (!st.empty()) { suf_exp.push_back(st.top()); st.pop(); }
				st.push(str[i]);
			}
		}
		while (!st.empty()) { suf_exp.push_back(st.top()); st.pop(); }

		stack<int> stk;
		for (int i = 0; i < suf_exp.size(); ++i) {
			if (suf_exp[i]>='0' && suf_exp[i]<='9') { stk.push(suf_exp[i]-'0'); continue; }
			int op1 = stk.top(); stk.pop();
			int op2 = stk.top(); stk.pop();
			if (suf_exp[i] == '+') stk.push(op2+op1);
			else if (suf_exp[i] == '-') stk.push(op2-op1);
			else if (suf_exp[i] == '*') stk.push(op2*op1);
			else stk.push(op2/op1);
		}
		return stk.top();
    }
};

int main()
{
	Solution sol;
	cout << sol.calculate("1*2-3/4+5*6-7*8+9/10") << endl;
	return 0;
}