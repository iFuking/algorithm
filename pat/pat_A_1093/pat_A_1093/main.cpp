#include <iostream>
#include <cstring>
using namespace std;

const int M = 1e9 + 7;
const int maxn = 1e5 + 10;
char str[maxn];

void solve()
{
	scanf("%s", str);
	int p_cnt = 0, a_cnt = 0, t_cnt = 0;

	for (int i = strlen(str)-1; i >= 0; --i)
	{
		if (str[i] == 'T') t_cnt = (t_cnt+1) % M;
		else if (str[i] == 'A') a_cnt = (a_cnt+t_cnt) % M;
		else p_cnt = (p_cnt+a_cnt) % M;
	}
	printf("%d\n", p_cnt);
	return;
}

int main(int argc, char *argv[])
{
	solve();
	return 0;
}

/*
01234567890123456
PTATPAATPTAATPATA
*/

// score (25): 25