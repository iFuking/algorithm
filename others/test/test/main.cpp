#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool cmp(const char &ch1, const char &ch2) { return ch1 > ch2; }

int main()
{
	string str = "681215";
	sort(str.begin(), str.end(), cmp);
	return 0;
}