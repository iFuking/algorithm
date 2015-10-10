#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXN 110

char spell[10][8] = {
	"zero", "one", "two", "three", "four", 
	"five", "six", "seven", "eight", "nine"
};

void solve()
{
	char str[MAXN]; scanf("%s", str);
	int sum = 0, sum_len, i;
	for (i = 0; i < strlen(str); ++i) sum += (str[i]-'0');
	if (sum == 0) { printf("zero\n"); return; }
	sum_len = (int)log10(sum*1.0) + 1;
	for (i = sum_len-1; i > 0; --i) {
		printf("%s ", spell[sum/(int)(pow(10.0, i))]);
		sum %= (int)(pow(10.0, i));
	}
	printf("%s\n", spell[sum]);
	return;
}

int main()
{
	solve();
	return 0;
}