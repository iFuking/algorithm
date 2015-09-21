#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 5;

bool cmp_incre(char ch1, char ch2) { return ch1 < ch2; }
bool cmp_decre(char ch1, char ch2) { return ch1 > ch2; }

void to_str(int n, char *str)
{
	int len = 0;
	while (n)
	{
		str[len++] = n%10 + '0';
		n /= 10;
	}
	while (len < maxn-1) str[len++] = '0';
	str[len] = '\0';
	return;
}

void solve()
{
	int n; scanf("%d", &n);
	char incre[maxn], decre[maxn];
	do {
		to_str(n, incre);
		to_str(n, decre);
		sort(incre, incre+4, cmp_incre);
		sort(decre, decre+4, cmp_decre);
		int inc = atoi(incre), dec = atoi(decre);
		n = dec-inc;
		if (n == 0) { printf("%04d - %04d = 0000\n", dec, inc); break; }
		printf("%04d - %04d = %04d\n", dec, inc, n);
	} while (n != 6174);
	return;
}

int main()
{
	solve();
	return 0;
}


/*
score 20 (20 in total)
*/