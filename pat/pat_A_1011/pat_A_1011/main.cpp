#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	float w, t, l;
}Odds;
const int maxn = 3;
Odds odds[maxn];
vector<char> results;

float which_buy(const Odds &odd)
{
	float max_res = -0.0;
	char ch;
	if (odd.w > max_res) { max_res = odd.w; ch = 'W'; }
	if (odd.t > max_res) { max_res = odd.t; ch = 'T'; }
	if (odd.l > max_res) { max_res = odd.l; ch = 'L'; }
	results.push_back(ch);
	return max_res;
}

void solve()
{
	for (int i = 0; i < maxn; ++i) scanf("%f %f %f", &odds[i].w, &odds[i].t, &odds[i].l);
	float product = 1.0;
	for (int i = 0; i < maxn; ++i) product *= which_buy(odds[i]);
	for (int i = 0; i < maxn; ++i) printf("%c ", results[i]);
	printf("%.2f\n", (product*0.65-1)*2);
	return;
}

int main()
{
	solve();
	return 0;
}