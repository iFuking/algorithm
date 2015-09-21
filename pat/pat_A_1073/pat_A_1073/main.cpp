#include <iostream>
#include <cstdio>
using namespace std;

const int maxe = 100;
const int maxf = 1e4 + maxe;
char n_sign, int_portion, e_sign;
char fra_portion[maxf];
char exp_portion[maxe];

void solve()
{
	n_sign = getchar(); int_portion = getchar();
	getchar();  // skip '.'
	char ch; int f_len = 0;
	while ((fra_portion[f_len++] = getchar()) != 'E') ;
	fra_portion[--f_len] = '\0';
	e_sign = getchar();
	int e_len = 0;
	while ((exp_portion[e_len++] = getchar()) != '\n') ;
	exp_portion[--e_len] = '\0';

	int exp_port = 0;
	for (int i = 0; i < e_len; ++i) exp_port = 10*exp_port+exp_portion[i]-'0';
	if (n_sign == '-') putchar(n_sign);
	if (exp_port == 0) printf("%c.%s\n", int_portion, fra_portion);
	else if (e_sign == '+') {
		if (exp_port >= f_len) {
			printf("%c%s", int_portion, fra_portion);
			for (int i = 0; i < exp_port-f_len; ++i) printf("0");
			printf("\n");
		} else {
			printf("%c", int_portion);
			for (int i = 0; i < f_len; ++i) {
				putchar(fra_portion[i]);
				if (i == exp_port-1) putchar('.');
			}
		}
	} else if (e_sign == '-') {
		for (int i = 0; i < exp_port; ++i) {
			putchar('0');
			if (i == 0) putchar('.');
		}
		printf("%c%s\n", int_portion, fra_portion);
	}
	return;
}

int main()
{
	solve();
	return 0;
}