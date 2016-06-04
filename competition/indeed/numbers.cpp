#include <iostream>
#include <string>
#include <map>
using namespace std;

void solve() {
	string s;
	long long M;
	cin >> s >> M;

	map<string, long long> cnt;
	map<long long, string> rev;

	for (long long m = 1; m <= M; ++m) {
		cnt[s] = m; rev[m] = s;

		char ch = s[0];
		for (int i = 0; i < ch-'0'-1; ++i) {
			s[i] = s[i+1];
		}
		if (ch-'0'-1 >= 0) {
			s[ch-'0'-1] = ch;
		}

		if (cnt[s] > 0) {
			long long remain = M-m;
			cout << rev[cnt[s]+remain%(m-cnt[s])] << endl;
			return;
		}
	}
	cout << s << endl;
	return;
}

int main() {
	solve();
	return 0;
}