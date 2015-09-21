#include <iostream>
#include <cstring>
#include <set>
using namespace std;

const int maxn = 1e4 + 10;

void solve()
{
	char ch, str1[maxn]; int len = 0;
	while ((ch = getchar()) != '\n') str1[len++] = ch;
	str1[len] = '\0';
	set<char> str2;
	while ((ch = getchar()) != '\n') str2.insert(ch);
	set<char>::iterator iter;
	for (int i = 0; i < len; ++i) {
		iter = str2.find(str1[i]);
		if (iter == str2.end()) putchar(str1[i]);
	}
	return;
}

int main()
{
	solve();
	return 0;
}