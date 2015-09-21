#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int happiness;
	vector<int> path;
}Path;

const int maxn = 210;
const int maxstr = 10;
int N, K;
string start_city;
int happiness[maxn], cost[maxn][maxn];
bool visit[maxn];
map<string, int> str2int;
map<int, string> int2str;
vector<int> path;
vector<vector<int>> paths;
int min_cost = 0x7fffffff;
vector<Path> p;

void dfs(int cityId, int c)
{
	if (cityId == str2int["ROM"])
	{
		if (c < min_cost) {
			paths.clear(); paths.push_back(path);
			min_cost = c;
		} else if (c == min_cost) paths.push_back(path);
		return;
	}
	for (int i = 0; i < N; ++i)
	{
		if (!visit[i] && cost[cityId][i]>0)
		{
			visit[i] = true;
			path.push_back(i);
			dfs(i, c+cost[cityId][i]);
			visit[i] = false;
			path.pop_back();
		}
	}
	return;
}

bool cmp(Path p1, Path p2)
{
	if (p1.happiness != p2.happiness) return p1.happiness > p2.happiness;
	return p1.happiness/p1.path.size() > p2.happiness/p2.path.size();
}

void solve()
{
	cin >> N >> K >> start_city;
	str2int[start_city] = 0;
	int2str[0] = start_city;
	for (int i = 1; i < N; ++i)
	{
		char city[maxstr]; int h;
		scanf("%s %d", city, &h);
		str2int[city] = i; int2str[i] = city;
		happiness[i] = h;
	}
	for (int i = 0; i < K; ++i)
	{
		char c1[maxstr], c2[maxstr]; int c;
		scanf("%s %s %d", c1, c2, &c);
		cost[str2int[c1]][str2int[c2]] = c;
		cost[str2int[c2]][str2int[c1]] = c;
	}

	visit[0] = true;
	dfs(0, 0);
	for (int i = 0; i < paths.size(); ++i)
	{
		int hap = 0;
		for (int j = 0; j < paths[i].size(); ++j) hap += happiness[paths[i][j]];
		Path item; item.happiness = hap; item.path = paths[i];
		p.push_back(item);
	}
	sort(p.begin(), p.end(), cmp);
	printf("%d %d %d %d\n", paths.size(), min_cost, p[0].happiness, p[0].happiness/p[0].path.size());
	printf("%s", start_city.c_str());
	for (int i = 0; i < p[0].path.size(); ++i) printf("->%s", int2str[p[0].path[i]].c_str());
	printf("\n");
	return;
}

int main()
{
	solve();
	return 0;
}