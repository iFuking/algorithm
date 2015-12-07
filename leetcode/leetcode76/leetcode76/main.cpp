#include <iostream>
#include <string>
using namespace std;

const int maxn = 128;

class Solution {
public:
	int need_find[maxn], has_found[maxn];

    string minWindow(string s, string t) {
		int slen = s.length(), tlen = t.length();
		for (int i = 0; i < tlen; ++i) ++need_find[t[i]];

		int count = 0;
		int max_begin, min_window=s.length()+1;
		for (int begin=0, end=0; end < slen; ++end) {
			if (need_find[s[end]] == 0) continue;
			++has_found[s[end]];
			if (has_found[s[end]] <= need_find[s[end]]) ++count;

			if (count == tlen) {
				while (need_find[s[begin]]==0 || 
					has_found[s[begin]]>need_find[s[begin]]) {
					if (has_found[s[begin]] > need_find[s[begin]]) --has_found[s[begin]];
					++begin;
				}
				if (end-begin+1 < min_window) {
					min_window = end-begin+1;
					max_begin = begin;
				}
			}
		}
		return min_window<=s.length() ? s.substr(max_begin, min_window) : "";
    }
};

int main()
{
	Solution sol;
	cout << sol.minWindow("a", "b") << endl;
	return 0;
}