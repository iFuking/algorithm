#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	if (n == 1) { cout << "Alice" << endl; return 0; }
	int stone; cin >> stone;
	int ans = stone;
	while (--n) { cin >> stone; ans ^= stone; }
	if (ans) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	return 0;
}