#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#define SMAXLEN 250000010
#define PMAXLEN 110
using namespace std;

char s[SMAXLEN], p[PMAXLEN];
std::vector<int> index;

int SUNDAY(char *text, char *patt)
{ 
    size_t  temp[256]; 
    size_t  *shift = temp; 
    size_t  i, patt_size = strlen(patt), text_size = 
        strlen(text); 
    int find = 0; 
    for( i=0; i < 256; i++ ) *(shift+i) = patt_size+1; 
    for( i=0; i < patt_size; i++ )  
        *(shift+unsigned char(*(patt+i))) = patt_size-i;
    //shift['s']=6 步,shitf['e']=5 以此类推 
    size_t  limit = text_size-patt_size+1; 
    for( i=0; i < limit; i += shift[ text[i+patt_size] ] )
        if( text[i] == *patt )
        { 
            char *match_text = text+i+1; 
            size_t  match_size = 1; 
            do
            {// 输出所有匹配的位置 
				if( match_size == patt_size ) { find = 1; index.push_back(i); } 
            }while( (*match_text++) == 
            patt[match_size++] ); 
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
	if (!SUNDAY(s, p)) cout << "Not Found" << endl;
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