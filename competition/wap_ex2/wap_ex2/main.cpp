/*
5 5
1 2
1 3
3 4
3 5
2 5
2 3
1 3
2 3
2 4
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

typedef struct CITY {
    int id;
    CITY *list;
}CITY;

const int maxn = 6;
int n, m;
CITY city[maxn];
bool festive[maxn], visit[maxn];

void readin()
{
    cin >> n >> m;
    memset(city, 0, sizeof(city));
    memset(visit, 0, sizeof(visit));

    memset(festive, 0, sizeof(festive));
    festive[1] = true;

    for (int i = 1; i <= n; i++)
        city[i].id = i;

    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;

        CITY *c1 = NULL;
        c1 = (CITY *)malloc(sizeof(CITY));
        c1->id = v;
        c1->list = city[u].list;
        city[u].list = c1;

        CITY *c2 = NULL;
        c2 = (CITY *)malloc(sizeof(CITY));
        c2->id = u;
        c2->list = city[v].list;
        city[v].list = c2;
    }
    return;
}

void bfs(int c, int &steps)
{
    queue<int> q;
    q.push(c);
    int head = 0, tail = 1, ttail = tail;
    while (!q.empty())
    {
        while (head < tail)
        {
			int cityId = q.front(); q.pop();
			if (!visit[cityId])
			{
				visit[cityId] = true;
				if (festive[cityId]) return;
				CITY *l = city[cityId].list;
				while (l != NULL)
				{
					if (!visit[l->id])
					{
						q.push(l->id);
						ttail++;
					}
					l = l->list;
				}
			}
            head++;
        }
        tail = ttail;
        steps++;
    }
    return;
}

void solve()
{
    for (int i = 0; i < m; i++)
    {
        int q, c, steps;
        cin >> q >> c;
        if (q == 1) festive[c] = true;
        else {
            bfs(c, steps=0);
			cout << steps << endl;
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    while (true)
    {
        readin();
        solve();
    }
	return 0;
}
