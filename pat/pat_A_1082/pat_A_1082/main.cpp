#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 15;
char number[][maxn] = {
	"ling", "yi", "er", "san", "si", 
	"wu", "liu", "qi", "ba", "jiu"
};
char measure[][maxn] = {
	"", "Shi", "Bai", "Qian", "Wan", "Yi"
};

void swap(char *ch1, char *ch2)
{
	char ch = *ch1;
	*ch1 = *ch2;
	*ch2 = ch;
	return;
}

void solve()
{
	char input[maxn]; scanf("%s", input);
	bool sign = false;
	char ge[maxn]; int len_ge = 0;
	char wan[maxn]; int len_wan = 0;
	char yi[maxn]; int len_yi = 0;
	for (int i = strlen(input)-1, j = 0; i >= 0 ; --i, ++j) {
		if (input[i] == '-') sign = true;
		else if (j < 4) ge[len_ge++] = input[i];
		else if (j < 8) wan[len_wan++] = input[i];
		else yi[len_yi++] = input[i];
	}
	ge[len_ge] = '\0'; wan[len_wan] = '\0', yi[len_yi] = '\0';
	for (int i = 0; i < len_ge/2; ++i) swap(&ge[i], &ge[len_ge-1-i]);
	for (int i = 0; i < len_wan/2; ++i) swap(&wan[i], &wan[len_wan-1-i]);

	if (sign) printf("Fu ");
	if (len_yi > 0) printf("%s Yi", number[yi[len_yi-1]-'0']);
	if (len_wan > 0) {
		if (len_yi>0 && len_wan<4) printf("ling ");
		for (int i = 0; i < len_wan; ++i) printf("%s %s ", number[wan[i]-'0'], measure[len_wan-1-i]);
	}
	return;
}

int main()
{
	solve();
	return 0;
}