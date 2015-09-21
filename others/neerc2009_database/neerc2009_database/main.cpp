#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cstring>
using namespace std;

void read();
void check();

const int rowmax = 10010;
const int colmax = 11;
const int strmax = 81;
int n, m;

char db[rowmax][colmax][strmax];
//int database[rowmax][colmax];

void spilt(char *linestr, int lineindex)
{
	char str[strmax];
	int i = 0, col = 0;
	for ( ; *linestr != '\0'; *linestr++)
	{
		if (*linestr == ',')
		{
			str[i] = '\0';
			strcpy(db[lineindex][col++], str);
			i = 0;
			continue;
		}
		str[i++] = *linestr;
	}
	str[i] = '\0';
	strcpy(db[lineindex][col], str);
	return;
}

void read()
{
	while (cin >> n >> m)
	{
		getchar();
		memset(db, 0, sizeof(db));
		char ch, line[strmax*colmax];
		for (int i = 0; i < n; i++)
		{
			int j = 0;
			while((ch = getchar()) != '\n')
				line[j++] = ch;
			line[j] = '\0';
			spilt(line, i);
		}

	// string to id
	/*map<string, int> stringid;
	int id = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			map<string, int>::iterator iter = stringid.find(db[i][j]);
			if (iter == stringid.end())
			{
				stringid[db[i][j]] = ++id;
				database[i][j] = id;
			} else {
				database[i][j] = iter->second;
			}
		}
	}*/
		check();
	}
	return;
}

void check()
{
	map<pair<string, string>, int> catsets;
	for (int c1 = 0; c1 < m-1; c1++) 
	{
		for (int c2 = c1+1; c2 < m; c2++)
		{
			for (int r = 0; r < n; r++)
			{
				pair<string, string> strpair = make_pair(db[r][c1], db[r][c2]);
				map<pair<string, string>, int>::iterator iter = catsets.find(strpair);
				if (iter != catsets.end())
				{
					cout << "NO" << endl;
					cout << iter->second+1 << " " << r+1 << endl;
					cout << c1+1 << " " << c2+1 << endl;
					return;
				} else
					catsets[strpair] = r;
			}
		}
	}
	cout << "YES" << endl;
	return;
}

int main()
{
	read();
	//check();
	//system("pause");
	return 0;
}