#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
	string s = "";
	for (int i = 0; i < n; ++i) s += '(';
	for (int i = 0; i < n; ++i) s += ')';
	
	vector<string> str;
	do {
		str.push_back(s);
	} while (next_permutation(s.begin(), s.end()));
	// for (int i = 0; i < str.size(); ++i) printf("%s\n", str[i].c_str());

	vector<string> gen;
	for (int i = 0; i < str.size(); ++i) {
		string s = str[i];
		stack<char> st; bool flag = false;
		for (int j = 0; j < s.length(); ++j) {
			if (s[j] == '(') st.push(s[j]);
			else {
				if (st.empty()) { flag = true; break; }
				if (st.top() == '(') st.pop();
				else { flag = true; break; }
			}
		}
		if (!flag) gen.push_back(s);
	}
	for (int i = 0; i < gen.size(); ++i) printf("%s\n", gen[i].c_str());
	return gen;
    }
};

bool cmp(const char &ch1, const char &ch2) { return ch1 < ch2; }

void solve()
{
	string str = "zee";
	sort(str.begin(), str.end(), cmp);
	// printf("%s\n", str.c_str());

	int cnt = 0;
	do {
		printf("%s\n", str.c_str());
		++cnt;
	} while (next_permutation(str.begin(), str.end()));
	printf("%d\n", cnt);
	return;
}

int main()
{
	// solve();
	Solution sol;
	sol.generateParenthesis(3);
	return 0;
}
