#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

const int maxn = 1010;
map<char, int> eva_bead;
map<char, int> shop_bead;
int eva_cnt = 0;   // eva has but shop doesn't
int shop_cnt = 0;  // shop has but shop doesn't
int extra = 0;
int missing = 0;

void solve()
{
	char ch;
	while ((ch = getchar()) != '\n') shop_bead[ch]++;
	while ((ch = getchar()) != '\n') eva_bead[ch]++;

	map<char, int>::iterator iter = eva_bead.begin();
	for ( ; iter != eva_bead.end(); ++iter) {
		if (shop_bead[iter->first] == 0) eva_cnt += iter->second;
	}

	iter = shop_bead.begin();
	for ( ; iter != shop_bead.end(); ++iter) {
		if (eva_bead[iter->first] > 0) {
			if (iter->second > eva_bead[iter->first]) {
				extra += (iter->second-eva_bead[iter->first]);
			} else if (iter->second < eva_bead[iter->first]) {
				missing += (eva_bead[iter->first]-iter->second);
			}
		} else shop_cnt += iter->second;
	}

	if (eva_cnt>0 || missing>0) printf("No %d\n", eva_cnt+extra);
	else if (shop_cnt>=0 || extra>=0) printf("Yes %d\n", shop_cnt+extra);
	return;
}

int main(int argc, char *argv[])
{
	solve();
	return 0;
}