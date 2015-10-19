#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
		int start = -1, long_len = 0;
		stack<pair<int, char>> st;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(') st.push(make_pair(i, s[i]));
			else {
				if (st.empty()) start = i;
				else {
					st.pop();
					if (!st.empty()) {
						int index = st.top().first;
						long_len = max(long_len, i-index);
					} else long_len = max(long_len, i-start);
				}
			}
		}
		return long_len;
    }
};

int main()
{
	Solution sol;
	cout << sol.longestValidParentheses("()((()()") << endl;
	return 0;
}