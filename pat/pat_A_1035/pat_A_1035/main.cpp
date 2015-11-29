#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 11;
const int maxch = 128;

typedef struct {
	char name[maxn];
	char password[maxn];
}ACCOUNT;

void solve()
{
	int N; cin >> N;
	char hash_ch[maxch];
	hash_ch['1']='@', hash_ch['0']='%', hash_ch['l']='L', hash_ch['O']='o';

	vector<ACCOUNT> account;
	for (int i = 0; i < N; ++i) {
		ACCOUNT a; scanf("%s %s", a.name, a.password);
		bool modified = false;
		for (int j = 0; j < strlen(a.password); ++j) {
			if (a.password[j]=='1' || a.password[j]=='0' ||
				a.password[j]=='l' || a.password[j]=='O') {
				a.password[j] = hash_ch[a.password[j]];
				modified = true;
			}
		}
		if (modified) account.push_back(a);
	}

	if (account.size() > 0) {
		printf("%d\n", account.size());
		for (int i = 0; i < account.size(); ++i) printf("%s %s\n", account[i].name, account[i].password);
		return;
	}

	if (N == 1) printf("There is 1 account and no account is modified\n");
	else printf("There are %d accounts and no account is modified\n", N);
	return;
}

int main()
{
	solve();
	return 0;
}