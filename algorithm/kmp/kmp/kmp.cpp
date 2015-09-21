#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <ctime>

#define SMAXLEN 250000010
#define PMAXLEN 110
using namespace std;

char s[SMAXLEN], p[PMAXLEN];
int anext[PMAXLEN];
std::vector<int> index;

void GetNext(char p[])
{
	memset(anext, 0, sizeof(anext));
	anext[0] = -1;
	int k = -1, j = 0;
	int plen = strlen(p);

	while(j < plen)
	{
		if (k == -1 || p[k] == p[j])
		{
			k++;
			j++;
			anext[j] = k;   // k and j increased
		} else {
			k = anext[k];   // find subpattern recursively
		}
	}
	return;
}

int KMP(char s[], char p[])
{
	int i = 0, j = 0;
	int slen = strlen(s), plen = strlen(p);
	assert(slen >= plen);
	bool find = 0;

	while (i < slen)
	{
		if (j == -1 || s[i] == p[j]) {
			i++, j++;
		} else {
			j = anext[j];
		}

		if (j == plen)
		{
			index.push_back(i-j);
			find = 1, j = 0;
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
	GetNext(p);
	if (!KMP(s, p)) cout << "Not Found" << endl;
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