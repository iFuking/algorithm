#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxn = 54;
vector<string> card;
const char color[] = {'S', 'H', 'C', 'D'};

void int2str(int n, string &str)
{
	string tmp = "";
	if (n < 10) str = n+'0';
	else {
		tmp += n/10+'0'; tmp += n%10+'0';
		str = tmp;
	}
	return;
}

void solve()
{
	for (int i = 0; i < sizeof(color); ++i) {
		for (int j = 1; j <= 13; ++j) {
			string number; int2str(j, number);
			card.push_back(color[i]+number);
		}
	}
	card.push_back("J1"); card.push_back("J2");

	vector<string> ans(maxn);
	int N; cin >> N;
	int pos[maxn];
	for (int i = 0; i < maxn; ++i) scanf("%d", &pos[i]);
	while (N--) {
		for (int i = 0; i < maxn; ++i) ans[pos[i]-1] = card[i];
		card = ans;
	}
	for (int i = 0; i < ans.size()-1; ++i) printf("%s ", ans[i].c_str());
	printf("%s\n", ans[ans.size()-1].c_str());
	return;
}

int main()
{
	solve();
	return 0;
}