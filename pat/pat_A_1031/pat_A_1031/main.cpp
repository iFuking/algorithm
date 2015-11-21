#include <iostream>
#include <string>
using namespace std;

void solve()
{
	string str; cin >> str;
	int n1 = (str.length()+2)/3, n2 = str.length()-2*n1;
	string str1, str2, str3;
	str1 = str.substr(0, n1);
	str2 = str.substr(n1, n2);
	str3 = str.substr(n1+n2);
	for (int i = 0; i < n1; ++i) {
		putchar(str1[i]);
		if (i == n1-1) printf("%s", str2.c_str());
		else for (int j = 0; j < n2; ++j) putchar(' ');
		putchar(str3[n1-1-i]);
		putchar('\n');
	}
	return;
}

int main()
{
	solve();
	return 0;
}