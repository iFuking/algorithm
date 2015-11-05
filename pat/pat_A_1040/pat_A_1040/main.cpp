#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 1e3 + 10;
int p[maxn*2];

void solve()
{
	char ch; string s = "";
	while ((ch = getchar()) != '\n') s += ch;
	string ss = "^#";
	for (int i = 0; i < s.length(); ++i) { ss += s[i]; ss += '#'; }
	ss += '$';

	int center = 0, right = 0;
	for (int i = 1; i < ss.length()-1; ++i) {
		int i_mirror = 2*center-i;
		p[i] = i<right? min(p[i_mirror], right-i) : 1;
		while (ss[i+p[i]] == ss[i-p[i]]) ++p[i];
		if (i+p[i] > right) { right = i+p[i]; center = i; }
	}

	int ans = 0;
	for (int i = 1; i < ss.length()-1; ++i) {
		if (p[i] > ans) ans = p[i];
	}
	printf("%d\n", ans-1);
	return;
}

int main()
{
	solve();
	return 0;
}