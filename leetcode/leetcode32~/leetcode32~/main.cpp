#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
		int start = -1, long_len = 0, s_len = s.length();
		stack<int> st;
		for (int i = 0; i < s_len; ++i) {
			if (s[i] == '(') st.push(i);
			else {
				if (st.empty()) start = i;
				else {
					st.pop();
					if (!st.empty()) long_len = max(long_len, i-st.top());
					else long_len = max(long_len, i-start);
				}
			}
		}
		return long_len;
    }
};

int main()
{
	Solution sol;
	cout << sol.longestValidParentheses(")()())") << endl;
	return 0;
}