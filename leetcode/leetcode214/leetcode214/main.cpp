#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e3 + 10;
int p[maxn];

class Solution {
public:
    string shortestPalindrome(string s) {
		if (s.length() < 2) return s;

		string ps = "^#";
		for (int i = 0; i < s.length(); ++i) {
			ps += s[i]; ps += '#';
		}
		ps += '$';

		memset(p, 0, sizeof(p));
		int c = 0, r = 0;
		int index_p, len_p = 0;
		for (int i = 1; i < ps.length()-1; ++i) {
			int i_mirror = 2*c-i;
			p[i] = r>i ? min(p[i_mirror], r-i) : 1;
			while (ps[i-p[i]] == ps[i+p[i]]) ++p[i];
			if (i+p[i] > r) { r = i+p[i]; c = i; }
			if (p[i]>len_p && i==p[i]) len_p = p[index_p=i];
		}

		string ret = "";
		if (len_p==2 || index_p>ps.length()/2) {
			for (int i = s.length()-1; i > 0; --i) ret += s[i];
			ret += s;
		} else {
			for (int i = ps.length()-2; i >= index_p+len_p; --i) { 
				if (ps[i] != '#') ret += ps[i];
			}
			for (int i = index_p-len_p+1; i < ps.length()-1; ++i) {
				if (ps[i] != '#') ret += ps[i];
			}
		}
		return ret;
    }
};

int main()
{
	Solution sol;
	cout << sol.shortestPalindrome("aabba") << endl;
	return 0;
}