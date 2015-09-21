#include <iostream>
#include <cstdio>
#include <cctype>
#include <map>
#include <string>
using namespace std;

struct AlphCmp {
	bool operator()(const string &str1, const string &str2) {
		return str1 < str2;
	}
};
const int maxn = 1e6 + 1e5;
const int maxw = 1e3;
map<string, int, AlphCmp> word_cnt;

void solve()
{
	char ch, word[maxw]; int len = 0;
	while ((ch = getchar()) != '\n')
	{
		if (!isalnum(ch) && len>0)  {
			word[len] = '\0';
			for (int i = 0; i < len; ++i) word[i] = tolower(word[i]);
			word_cnt[word]++;
			len = 0;
		} else if (isalnum(ch)) word[len++] = ch;
	}
	if (len > 0) {
		word[len] = '\0';
		for (int i = 0; i < len; ++i) word[i] = tolower(word[i]);
		word_cnt[word]++;
	}

	string common; int times = -1;
	map<string, int, AlphCmp>::iterator iter = word_cnt.begin();
	for ( ; iter != word_cnt.end(); ++iter) {
		if (iter->second > times) times = word_cnt[common=iter->first];
	}
	printf("%s %d\n", common.c_str(), times);
	return;
}

int main()
{
	solve();
	return 0;
}


/*
Can1: "Can a can can a can?  It can!"

score 25 (25 in total)
*/