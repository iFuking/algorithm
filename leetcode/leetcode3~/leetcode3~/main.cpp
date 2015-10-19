#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 128;
int pre[maxn];

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		for (int i = 0; i < maxn; ++i) pre[i] = -1;
		int ans = 0, left = -1;
		for (int i = 0; i < s.length(); ++i) {
			if (pre[s[i]]>=0 && left<pre[s[i]]) left = pre[s[i]];
			pre[s[i]] = i;
			ans = max(ans, i-left);
		}
		return ans;
    }
};

int main()
{
	Solution sol;
	cout << sol.lengthOfLongestSubstring("abba") << endl;
	return 0;
}