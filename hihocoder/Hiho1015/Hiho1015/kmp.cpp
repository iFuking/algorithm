#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXP 10010
#define MAXS 1000010
using namespace std;

int N;
char P[MAXP], S[MAXS];
int lenp, lens;
int anext[MAXP];

void GetNext()
{
	int k = -1, j = 0;
	memset(anext, 0, sizeof(anext));
	anext[0] = -1;
	lenp = strlen(P);
	while (j < lenp)
	{
		if (k == -1 || P[k] == P[j])
		{
			k++;
			j++;
			anext[j] = k;
		} else {
			k = anext[k];
		}
	}
	return;
}

int KMP()
{
	int cnt = 0;
	lens = strlen(S);
	for (int i = 0, j = 0; i < lens; )
	{
		if (j == -1 || S[i] == P[j])
		{
			i++;
			j++;
		} else {
			j = anext[j];
		}

		if (j == lenp) cnt++;
	}
	return cnt;
}

int main(int argc, char *argv[])
{
	cin >> N;
	while(N--)
	{
	    scanf("%s %s", P, S);
		//cin >> P >> S;
		GetNext();
		cout << KMP() << endl;
	}

	//system("pause");
	return 0;
}