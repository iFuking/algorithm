#include <iostream>
#include <cstring>
#include <vector>
#include <cctype>
using namespace std;

const int maxlen = 81;
char s1[maxlen], s2[maxlen];
const int maxchar = 128;
bool visit[maxchar];
vector<char> worn;

void solve()
{
	scanf("%s %s", s1, s2);
	for (int i = 0; i < strlen(s1); ++i)
	{
		bool have = false;
		for (int j = 0; j < strlen(s2); ++j) {
			if (s1[i] == s2[j]) { have = true; break; }
		}
		if (!have) {
			if (!visit[toupper(s1[i])]) {
				visit[toupper(s1[i])] = true;
				worn.push_back(toupper(s1[i]));
			}
		}
	}

	for (int i = 0; i < worn.size(); ++i) printf("%c", worn[i]);
	printf("\n");
	return;
}

int main()
{
	solve();
	return 0;
}