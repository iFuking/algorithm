#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 305;
int p[maxn];

class Palindrome {
public:
    int getLongestPalindrome(string A, int n) {
		string ret = ""; ret += '^';
		for (int i = 0; i < A.length(); ++i) { ret += '#'; ret += A[i]; }
		ret += '#'; ret += '$';

		int index = 0, pr = 0;
		memset(p, 0, sizeof(p));
		for (int i = 1; i < ret.length()-1; ++i) {
			int i_mirror = 2*index-i;
			if (i >= pr) p[i] = 1;
			else if (pr-i > p[i_mirror]) p[i] = p[i_mirror];
			else p[i] = pr-i;
			// p[i] = pr>i ? min(p[i_mirror], pr-i) : 1;

			while (ret[i+p[i]] == ret[i-p[i]]) ++p[i];
			if (i+p[i] > pr) { pr = i+p[i]; index = i; }
		}

		int res = 0;
		for (int i = 0; i < ret.length(); ++i) {
			if (p[i] > res) res = p[i];
		}
		return res-1;
	}
};

int main()
{
	Palindrome sol;
	cout << sol.getLongestPalindrome("ccbcabaabba",11) << endl;
	return 0;
}