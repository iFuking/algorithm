#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

void solve() {
	char ch, pre;
	bool start = false, has_space = false;
	while ((ch = getchar()) != EOF) {
		if (ch == '\n') {
			putchar(ch); start = false;
			pre = ch;
			continue;
		}
		if (ch == '.') {
			putchar(ch); start = false;
			pre = ch;
			continue;
		}
		if (ch == ',') {
			putchar(ch); pre = ch;
			continue;
		}

		if (isspace(ch)) {
			if (start && isalpha(pre)) {
				pre = ch;
			}
			continue;
		}

		if (!start) {
			start = true;
			if (pre==' ' || pre=='\t' || pre=='.') {
				putchar(' ');
			}
			putchar(toupper(ch));
			pre = ch;
			continue;
		}

		if (pre==' ' || pre=='\t' || pre==',') {
			putchar(' ');
		}
		putchar(tolower(ch));
		pre = ch;

	}
	return;
}

int main() {
	solve();
	return 0;
}