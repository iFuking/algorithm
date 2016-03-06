#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <ctime>

#define BADCH_LEN 256
#define MAXSIZE 256
#define SMAXLEN 250000010
#define PMAXLEN 1010
using namespace std;

char s[SMAXLEN], p[PMAXLEN];
std::vector<int> index;

int max(int a, int b)
{
	return a > b ? a : b;
}

void PreBadch(char p[], int badch[])
{
	int plen = strlen(p);

	for (int i = 0; i < BADCH_LEN; i++)
		badch[i] = plen;

	for (int i = 0; i < plen-1; i++)
		badch[p[i]] = plen-1-i;
	return;
}

void Suffix(char p[], int suff[])
{
	int plen = strlen(p);
	suff[plen-1] = plen;
	
	for (int i = plen-2; i >= 0; i--)
	{
		int j;
		for (j = i; j>=0 && p[j]==p[plen-1-i+j]; j--);
		suff[i] = i-j;
	}
	return;
}

void Suffix_(char p[], int suff[])
{
	int f, g, i;
	int plen = strlen(p);

	suff[plen-1] = plen;
	g = plen - 1;
	for (int i = plen-2; i >= 0; i--)
	{
		if (i > g && suff[i+plen-1-f] < i - g)
			suff[i] = suff[i+plen-1-f];
		else {
			if (i < g) g = i;
			f = i;
			while (g >= 0 && p[g] == p[g+plen-1-f]) g--;
			suff[i] = f - g;
		}
	}
}

void PreGoodsuff(char p[], int goodsuff[])
{
	int plen = strlen(p);
	int suff[MAXSIZE];

	Suffix_(p, suff);

	for (int i = 0; i < plen; i++)
		goodsuff[i] = plen;

	for (int i = plen-1, j = 0; i >= 0; i--)
		if (suff[i] == i+1)
			for ( ; j < plen-1-i; j++)
				if (goodsuff[j] == plen)
					goodsuff[j] = plen-1-i;

	for (int i = 0; i < plen-1; i++)
		goodsuff[plen-1-suff[i]] = plen-1-i;

	return;
}

int BM(char s[], char p[])
{
	int slen = strlen(s), plen = strlen(p);
	int badch[BADCH_LEN], goodsuff[MAXSIZE];
	int find = 0;

	PreBadch(p, badch);
	PreGoodsuff(p, goodsuff);

	for (int i = 0; i < slen-plen+1; )
	{
		int j;
		for (j = plen-1; j>=0 && p[j]==s[i+j]; j--);
		if (j < 0)
		{
			find = 1;
			index.push_back(i);
			i += goodsuff[0];
		} else {
			i += max(badch[s[i+j]]-plen+1+j, goodsuff[j]);
		}
	}

	return find;
}

void ReadStr(char *filename)
{
	FILE *fr = NULL;
	if ((fr = fopen(filename, "r")) == NULL)
		exit(-1);
	fgets(s, SMAXLEN, fr);
	gets(p);
}

int main(int argc, char *argv[])
{
	ReadStr(argv[1]);
	clock_t start = clock();
	if(!BM(s, p)) cout << "Not Found" << endl;
	//else {
	//	std::vector<int>::iterator iter = index.begin();
	//	for ( ; iter != index.end(); ++iter)
	//		cout << *iter << " ";
	//	cout << endl;
	//}
	clock_t end = clock();
	cout << end-start << "ms" << endl;

	system("pause");
	return 0;
}