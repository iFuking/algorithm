#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

void solve() {
	string s; cin >> s;
	set<string> st, ans;
	for (int i = 0; i < s.length(); ++i) {
		for (int j = 0; j < 4; ++j) {
			string str = s;
			char ch = 'a'+j;
			str[i] = ch;
			sort(str.begin(), str.end());
			st.insert(str);
		}
	}

	set<string>::iterator iter = st.begin();
	for ( ; iter != st.end(); ++iter) {
		s = *iter;
		// cout << s << endl;
		do {
			ans.insert(s);
		} while (next_permutation(s.begin(), s.end()));
	}
	// cout << endl;

	set<string>::iterator it = ans.begin();
	for ( ; it != ans.end(); ++it) {
		cout << *it << endl;
	}
	return;
}

int main() {
	solve();
	return 0;
}