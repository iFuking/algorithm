#include <iostream>
#include <string>
using namespace std;

char to_char(int n)
{
	if (n < 10) return n+'0';
	return n-10+'A';
}

string base_13(int n)
{
	string ans = "";
	ans += to_char(n/13); ans += to_char(n%13);
	return ans;
}

void solve()
{
	int r, g, b; cin >> r >> g >> b;
	string ans = base_13(r)+base_13(g)+base_13(b);
	printf("#%s", ans.c_str());
	return;
}

int main()
{
	solve();
	return 0;
}