#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	vector<int> r;
	int cost;
	int happiness;
}ROUTE;
const int maxn = 205;
int N, K;
int h[maxn], c[maxn][maxn];
string start_city;
map<string, int> str2int;
map<int, string> int2str;
bool visit[maxn];
vector<ROUTE> records;
ROUTE route;

void init()
{
	memset(h, 0, sizeof(h));
	memset(c, 0, sizeof(c));
	memset(visit, 0, sizeof(visit));
    cin >> N >> K;
    cin >> start_city;
    str2int[start_city] = 0;
	int2str[0] = start_city;
    h[0] = 0;
    for (int i = 0; i < N-1; ++i)
    {
        string city; int happiness;
        cin >> city >> happiness;
        str2int[city] = i+1;
		int2str[i+1] = city;
        h[i+1] = happiness;
    }
    for (int i = 0; i < K; ++i)
    {
        string c1, c2; int cost;
        cin >> c1 >> c2 >> cost;
        c[str2int[c1]][str2int[c2]] = cost;
		c[str2int[c2]][str2int[c1]] = cost;
    }
    return;
}

void dfs(int cityId)
{
	if (cityId == str2int["ROM"]) { records.push_back(route); return; }
	for (int i = 0; i < N; ++i) 
	{
		if (!visit[i] && c[cityId][i]>0) 
		{
			visit[i] = true;
			route.r.push_back(i);
			route.cost += c[cityId][i];
			route.happiness += h[i];
			dfs(i);
			visit[i] = false;
			route.r.pop_back();
			route.cost -= c[cityId][i];
			route.happiness -= h[i];
		}
	}
	return;
}

bool cmp(ROUTE a, ROUTE b)
{
	if (a.cost != b.cost) return a.cost < b.cost;
	else if (a.happiness != b.happiness) return a.happiness > b.happiness;
	return a.happiness/a.r.size() > b.happiness/b.r.size();
}

void solve()
{
	init();
	visit[str2int[start_city]] = true;
	dfs(str2int[start_city]);
	
	sort(records.begin(), records.end(), cmp);
	int cnt = 0;
	vector<ROUTE>::iterator iter = records.begin();
	for ( ; iter != records.end(); ++iter) {
		if (iter->cost == records.begin()->cost) ++cnt;
	}
	iter = records.begin();
	cout << cnt << " " << iter->cost << " " << iter->happiness << " " << (int)(iter->happiness/iter->r.size()) << endl;
	cout << start_city;
	vector<int>::iterator it = iter->r.begin();
	for ( ; it != iter->r.end(); ++it) cout << "->" << int2str[*it];
	cout << endl;
	return;
}

int main()
{
	solve();
    return 0;
}