#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

int char2int(char ch) {
	if (ch == '2') return ch-'1'+14;
	else if (isdigit(ch)) return ch-'0';
	else if (ch == 'A') return 14;
	else if (ch == 'J') return 11;
	else if (ch == 'Q') return 12;
	return 13;
}

char int2char(int n) {
	if (n == 15) return n-14+'1';
	else if (n>=3 && n<=10) return n+'0';
	else if (n == 14) return 'A';
	else if (n == 11) return 'J';
	else if (n == 12) return 'Q';
	return 'K';
}

void solve() {
	char ch, pre;
	bool is_next = false;
	vector<int> v1, v2;
	while ((ch = getchar()) != '\n') {
		if (ch == 'j') {
			while ((ch = getchar()) != '\n') ;
			printf("joker JOKER\n");
			return;
		}

		if (isspace(ch)) continue;
		if (ch == '-') { is_next = true; continue; }
		if (ch == '0') {
			if (!is_next) {
				v1.pop_back();
				v1.push_back(10);
			} else {
				v2.pop_back();
				v2.push_back(10);
			}
			continue;
		}

		if (!is_next) {
			v1.push_back(char2int(ch));
		} else {
			v2.push_back(char2int(ch));
		}

		pre = ch;
	}

	if (v1.size()==4 || v2.size()==4) {
		if (v1.size() != 4) {
			for (int i = 0; i < v2.size()-1; ++i) {
				if (v2[i] == 10) printf("10 ");
				else printf("%c ", int2char(v2[i]));
			}
			if (v2[3] == 10) printf("10\n");
			else printf("%c\n", int2char(v2[v2.size()-1]));
		} else if (v2.size() != 4) {
			for (int i = 0; i < v1.size()-1; ++i) {
				if (v1[i] == 10) printf("10 ");
				else printf("%c ", int2char(v1[i]));
			}
			if (v1[3] == 10) printf("10\n");
			else printf("%c\n", int2char(v1[v1.size()-1]));
		} else {
			for (int i = 0; i < v1.size()-1; ++i) {
				if (max(v1[i], v2[i]) == 10) printf("10 ");
				else printf("%c ", int2char(max(v1[i], v2[i])));
			}
			if (max(v1[3], v2[3]) == 10) printf("10\n");
			else printf("%c\n", int2char(max(v1[3], v2[3])));
		}
	} else if (v1.size() == v2.size()) {
		for (int i = 0; i < v1.size()-1; ++i) {
			if (max(v1[i], v2[i]) == 10) printf("10 ");
			else printf("%c ", int2char(max(v1[i], v2[i])));
		}
		if (max(v1[v1.size()-1], v2[v2.size()-1]) == 10) printf("10\n");
		else printf("%c\n", int2char(max(v1[v1.size()-1], v2[v2.size()-1])));
	} else {
		printf("ERROR\n");
	}
	return;
}

int main() {
	solve();
	return 0;
}
