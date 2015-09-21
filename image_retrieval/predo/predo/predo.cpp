#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXLEN 110
using namespace std;

int main(int argc, char *argv[])
{
	FILE *fr = NULL, *fw = NULL;
	if ((fr = fopen(argv[1], "r")) == NULL)
		exit(-1);
	fw = fopen(argv[2], "w");

	char ch;
	while ((ch = fgetc(fr)) != EOF)
	{
		if (ch == '\n') fputc(' ', fw);
		else fputc(ch, fw);
	}

	fclose(fr);
	fclose(fw);

	system("pause");
	return 0;
}