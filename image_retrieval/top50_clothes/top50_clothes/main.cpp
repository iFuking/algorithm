#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct {
	int index;
	int fea;
}Node;

const int maxfea = 150000;
Node matfea[maxfea];
int leng;

bool operator<(const Node &a, const Node &b)
{
	if (a.fea != b.fea)
		return a.fea > b.fea;
	return a.index < b.index;
}

int main(int argc, char *argv[])
{
	FILE *re = NULL;
	re = fopen(argv[1], "r");
	while (!feof(re))
	{
		matfea[leng].index = leng+1;
		fscanf(re, "%d", &matfea[leng].fea);
		leng++;
	}
	sort(matfea, matfea+leng);
	return 0;
}