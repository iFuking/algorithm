#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

bool can_pali(const string &s) {
	string str;
	for (int i = 0; i < s.length()/2; ++i) {
		if (s[i] != s[s.length()-1-i]) {
			str = s.substr(0, s.length()-i);
			str += s[i];
			str += s.substr(s.length()-i);
			// printf("%s\n", str.c_str());
			break;
		}
	}

	bool flag = true;
	for (int i = 0; i < str.length()/2; ++i) {
		if (str[i] != str[str.length()-1-i]) {
			flag = false;
			break;
		}
	}
	return flag;
}

void solve() {
	char str[11];
	while (scanf("%s", str) != EOF) {
		string s = str;
		bool flag = can_pali(s);

		for (int i = 0; i < s.length()/2; ++i) {
			swap(s[i], s[s.length()-1-i]);
		}
		flag = flag | can_pali(s);
		
		if (flag) {
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	
	return;
}

int main() {
	solve();
	return 0;
}