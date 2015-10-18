#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e3 + 10;
int p[maxn];

class Solution {
public:
    string longestPalindrome(string s) {
        string ret = "^";
		for (int i = 0; i < s.length(); ++i) { ret += '#'; ret += s[i]; }
		ret += '#'; ret += '$';

		int index = 0, pr = 0;
		memset(p, 0, sizeof(p));
		for (int i = 1; i < ret.length()-1; ++i) {
			int i_mirror = 2*index-1;
			p[i] = pr>i ? min(p[i_mirror], pr-i) : 1;
			while (ret[i-p[i]] == ret[i+p[i]]) ++p[i];
			if (i+p[i] > pr) { pr = i+p[i]; index = i; }
		}

		int ans = 0, flag;
		for (int i = 1; i < ret.length(); ++i) {
			if (p[i] > ans) ans = p[flag=i];
		}
		string res = "";
		for (int i = flag-ans+1; i < flag+ans-1; ++i) {
			if (ret[i] != '#') res += ret[i];
		}
		return res;
    }
};

int main()
{
	Solution sol;
	cout << sol.longestPalindrome("madam") << endl;
	return 0;
}