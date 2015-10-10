#include <iostream>
#include <string>
#include <cctype>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        string str = "";
		for (int i = 0; i < s.length(); ++i) {
			if (!isspace(s[i])) str += s[i];
		}

		string ss = "";
		vector<string> suf_exp;
		stack<char> st;
		for (int i = 0; i < str.length(); ++i) {
			if (str[i]>='0' && str[i]<='9') { ss += str[i]; continue; }
			if (str[i]=='*' || str[i]=='/') {
				suf_exp.push_back(ss); ss = "";
				while (!st.empty() && (st.top()=='*'||st.top()=='/')) {
					string op = "";
					suf_exp.push_back(op+=st.top()); st.pop();
				}
				st.push(str[i]);
			} else {
				suf_exp.push_back(ss); ss = "";
				while (!st.empty()) {
					string op = "";
					suf_exp.push_back(op+=st.top()); st.pop();
				}
				st.push(str[i]);
			}
		}
		suf_exp.push_back(ss);
		while (!st.empty()) {
			string op = "";
			suf_exp.push_back(op+=st.top()); st.pop();
		}

		stack<int> stk;
		for (int i = 0; i < suf_exp.size(); ++i) {
			if (suf_exp[i]!="+" && suf_exp[i]!="-" && suf_exp[i]!="*" && suf_exp[i]!="/") { stk.push(atoi(suf_exp[i].c_str())); continue; }
			int op1 = stk.top(); stk.pop();
			int op2 = stk.top(); stk.pop();
			if (suf_exp[i] == "+") stk.push(op2+op1);
			else if (suf_exp[i] == "-") stk.push(op2-op1);
			else if (suf_exp[i] == "*") stk.push(op2*op1);
			else stk.push(op2/op1);
		}
		return stk.top();
    }
};

int main()
{
	Solution sol;
	cout << sol.calculate("100000000/1/2/3/4/5/6/7/8/9/10") << endl;
	return 0;
}