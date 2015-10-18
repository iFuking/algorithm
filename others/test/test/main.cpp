#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool cmp(const char &ch1, const char &ch2) { return ch1 > ch2; }

int main()
{
	int i;
	while (cin >> i) {
		int res = i & 1;
		cout << res << endl;
	}
	return 0;
}