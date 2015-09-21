#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 12;
char N1[maxn], N2[maxn];
int tag, radix;

int char2int(char ch)
{
	if (ch>='0' && ch<='9') return ch-'0';
	return ch-'a'+10;
}

long long str2int(char str[], long long radix)
{
	long long res = 0;
	for (int i = 0; str[i] != '\0'; ++i) res = radix*res + char2int(str[i]);
	return res;
}

int least_radix(char str[])
{
	int least_radix = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i]>='0' && str[i]<='9') {
			if (str[i]-'0'+1 > least_radix) least_radix = str[i]-'0'+1;
		} else {
			if (str[i]-'a'+11 > least_radix) least_radix = str[i]-'a'+11;
		}
	}
	return least_radix;
}

int b_search(int left, int right, long long n)
{
	while (left <= right)
	{
		int mid = (left+right) >> 1;
		long long m = str2int(N2, mid);
		if (m < n) left = mid+1;
		else if (m > n) right = mid-1;
		else return mid;
	}
	return 0;
}

void solve()
{
	scanf("%s %s %d %d", N1, N2, &tag, &radix);
	if (tag == 2) {
		char tmp[maxn];
		strcpy(tmp, N1); strcpy(N1, N2); strcpy(N2, tmp);
	}
	long long n1, n2;
	n1 = str2int(N1, radix);
	int r_left = least_radix(N2), r_right = 325;
	// int r = least_radix(N2);
	// for ( ; (n2=str2int(N2,r)) < n1; ++r) ;
	int r = b_search(r_left, r_right, n1);
	if (r) printf("%d\n", r);
	else printf("Impossible\n");
	return;
}

int main(int argc, char *argv[])
{
	solve();
	return 0;
}

// cfga091 438228307 1 18