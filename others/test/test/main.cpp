#include <iostream>
using namespace std;

int mul(int a, int b)
{
	int ans = 0;
	for (int i = 0; b; ++i, b>>=1) {
		if (b&1) {
			ans += (a<<i);
		}
	}
	return ans;
}

int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b)) printf("%d\n", mul(a, b));
	return 0;
}