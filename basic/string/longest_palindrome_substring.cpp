#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int maxn = 1e3 + 10;
int p[maxn];
string ss = "^#";

int longest_palindrome_substring_length(const string &s) {
	for (int i = 0; i < s.length(); ++i) {
		ss += s[i]; ss += '#';
	}
	ss += '$';

	int c = 0, r = 0, longest_length = 1;
	for (int i = 1; i < ss.length()-1; ++i) {
		int i_mirror = 2*c-i;
		p[i] = i<r ? min(p[i_mirror], r-i): 1;
		while (ss[i-p[i]] == ss[i+p[i]]) ++p[i];
		if (i+p[i] > r) {
			r = i+p[i]; c = i;
		}

		if (p[i] > longest_length) {
			longest_length = p[i];
		}
	}

	return longest_length-1;
}

string longest_palindrome_substring() {
	int longest_length = 0, index;
	for (int i = 1; i < ss.length()-1; ++i) {
		if (p[i] > longest_length) {
			longest_length = p[index=i];
		}
	}

	string s;
	for (int i = index-longest_length+1; i < index+longest_length; ++i) {
		if (ss[i] != '#') s += ss[i];
	}
	return s;
}

void solve() {
	string s; cin >> s;
	printf("%d\n", longest_palindrome_substring_length(s));
	printf("%s\n", longest_palindrome_substring().c_str());
	return;
}

int main() {
	solve();
	return 0;
}