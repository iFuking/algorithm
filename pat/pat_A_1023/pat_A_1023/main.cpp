#include <iostream>
#include <string>
using namespace std;

const int maxn = 21;
int a[maxn], doubled[maxn];
const int max_digit = 10;
int c1[max_digit], c2[max_digit];

void solve()
{
	string s; cin >> s;
	for (int i = 0; i < s.length(); ++i) {
		a[i] = s[s.length()-1-i]-'0';
		++c1[a[i]];
	}

	for (int i = 0; i < s.length()+1; ++i) {
		doubled[i] = (doubled[i]+a[i]*2) % 10;
		doubled[i+1] = a[i]*2/10;
	}

	int len = s.length();
	while (!doubled[len]) --len;
	++len;

	if (s.length() < len) {
		printf("No\n");
		for (int i = len-1; i >= 0; --i) printf("%d", doubled[i]);
		printf("\n"); return;
	}
	for (int i = 0; i < len; ++i) ++c2[doubled[i]];
	bool flag = false;
	for (int i = 0; i < max_digit; ++i) {
		if (c1[i] != c2[i]) { flag = true; break; }
	}
	if (flag) printf("No\n");
	else printf("Yes\n");
	for (int i = len-1; i >= 0; --i) printf("%d", doubled[i]);
	printf("\n");
	return;
}

int main()
{
	solve();
	return 0;
}