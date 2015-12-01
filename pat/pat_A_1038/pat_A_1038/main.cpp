#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 9;
vector<string> numbers;

bool cmp(const string &s1, const string &s2) { return s1+s2 < s2+s1; }

void solve()
{
	int N; cin >> N;
	for (int i = 0; i < N; ++i) {
		char num[maxn]; scanf("%s", num);
		numbers.push_back(num);
	}

	sort(numbers.begin(), numbers.end(), cmp);
	string res = "";
	for (int i = 0; i < numbers.size(); ++i) res += numbers[i];
	int index = 0;
	for ( ; index < res.length(); ++index) {
		if (res[index] != '0') break;
	}
	if (index == res.length()) { printf("0\n"); return; }
	printf("%s\n", res.substr(index).c_str());
	return;
}

int main()
{
	solve();
	return 0;
}


/*
5 32 321 3214 0229 87
*/