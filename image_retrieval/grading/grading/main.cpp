#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cmath>
using namespace std;

const int WORDNUMS = 2;
const int WORDLINE = 20;
const int LINELENGTH = 81;
char words[WORDNUMS][WORDLINE];
const int IMGNUMS = 300;
char dstimg[IMGNUMS][LINELENGTH];
const int SRIMGNUM = 6;
const int DSTIMGNUM = 10;
const int FNLENGTH = 20;
char dst[SRIMGNUM][DSTIMGNUM][FNLENGTH] = 
{
	{"clothes_101640.jpg", "clothes_125528.jpg", "clothes_154678.jpg", 
	"clothes_172341.jpg", "clothes_184752.jpg", "clothes_205327.jpg", 
	"clothes_211982.jpg"}, 

	{"clothes_119656.jpg", "clothes_162346.jpg", "clothes_184037.jpg", 
	"clothes_194513.jpg", "clothes_229836.jpg", "clothes_241370.jpg"}, 

	{"clothes_122164.jpg", "clothes_138153.jpg", "clothes_162882.jpg", 
	"clothes_165839.jpg", "clothes_194378.jpg", "clothes_218266.jpg"}, 

	{"shoes_174906.jpg", "shoes_194832.jpg"}, 

	{"shoes_145394.jpg", "shoes_201349.jpg", "shoes_210819.jpg", 
	"shoes_237941.jpg", "shoes_245538.jpg"}, 

	{"shoes_129073.jpg", "shoes_131837.jpg", "shoes_142093.jpg", 
	"shoes_223576.jpg"}
};

double rel(int n, int srimgid)
{
	for (int i = 0; strcmp(dst[srimgid][i], "") != 0; i++)
		if (strcmp(dstimg[50*srimgid+n-1], dst[srimgid][i]) == 0)
			return 2.0;
	return 0.0;
}

double DCG(int srimgid)
{
	double sum = 0.0;
	sum += rel(1, srimgid);
	for (int i = 2; i <= 50; i++)
		sum += rel(i, srimgid)/(log(i*1.0)/log(2.0));
	return sum;
}

double IDCG()
{
	double rel1 = 2.0, sum = 0.0;
	sum += rel1;
	for (int i = 2; i <= 10; i++)
		sum += 2/(log(i*1.0)/log(2.0));
	return sum;
}

double NDCG(int srimgid)
{
	return DCG(srimgid)/IDCG();
}

double avgNDCG()
{
	double closum = 0.0, shosum = 0.0;
	for (int i = 0; i < SRIMGNUM; i++)
	{
		if (i < 3) closum += NDCG(i);
		else shosum += NDCG(i);
	}
	return 0.6*1.0/3*closum + 0.4*1.0/3*shosum;
}

//char dst_clothes_250001[][19] = {
//	"clothes_101640.jpg", "clothes_125528.jpg", "clothes_154678.jpg", 
//	"clothes_172341.jpg", "clothes_184752.jpg", "clothes_205327.jpg", 
//	"clothes_211982.jpg"
//};
//char dst_clothes_250002[][19] = {
//	"clothes_119656.jpg", "clothes_162346.jpg", "clothes_184037.jpg", 
//	"clothes_194513.jpg", "clothes_229836.jpg", "clothes_241370.jpg"
//};
//char dst_clothes_250003[][19] = {
//	"clothes_122164.jpg", "clothes_138153.jpg", "clothes_162882.jpg", 
//	"clothes_165839.jpg", "clothes_194378.jpg", "clothes_218266.jpg"
//};
//char dst_shoes_250001[][17] = {
//	"shoes_174906.jpg", "shoes_194832.jpg"
//};
//char dst_shoes_250002[][17] = {
//	"shoes_145394.jpg", "shoes_201349.jpg", "shoes_210819.jpg", 
//	"shoes_237941.jpg", "shoes_245538.jpg"
//};
//char dst_shoes_250003[][17] = {
//	"shoes_129073.jpg", "shoes_131837.jpg", "shoes_142093.jpg", 
//	"shoes_223576.jpg"
//};

void split(char s[], char ch)
{
	int wordnum = 0, j = 0;
	memset(words, 0, sizeof(words));
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ch) { 
			words[wordnum++][j] = '\0'; j = 0;
		} else {
			words[wordnum][j++] = s[i];
		}
	}
	words[wordnum++][j] = '\0';
	return;
}

void read(char filename[])
{
	ifstream fin(filename);
	char line[LINELENGTH];
	memset(line, 0, sizeof(line));
	memset(dstimg, 0, sizeof(dstimg));
	bool ignore = false;
	for (int i = 0; fin.getline(line,LINELENGTH); i++)
	{
		if (!ignore) { ignore = true; continue; }
		split(line, ',');
		strcpy(dstimg[i-1], words[1]);
	}
	return;
}

int main(int argc, char *argv[])
{
	read(argv[1]);
	cout << avgNDCG() << endl;
	return 0;
}