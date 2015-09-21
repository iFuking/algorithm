/*
3
2 5
0
0 1 0 0 0
0 0 0 1 0
4 6
1
0 1 1 0 0 0
0 0 1 0 1 1 
0 1 1 1 1 0
0 1 1 1 0 0
2 2
0
0 1
1 0
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 22;
int m, n, k;
int matrix[maxn][maxn];
typedef struct {
	int x, y, k;
	int steps;
}Point;
Point start_point, end_point;
int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool visit[maxn][maxn][maxn];  // why three dimession
							   // explanation: check if (x, y) with k steps visited
void init()
{
	cin >> m >> n >> k;
	memset(matrix, 0, sizeof(matrix));
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) cin >> matrix[i][j];
	start_point.x = 1, start_point.y = 1, start_point.k = k, start_point.steps = 0;
	end_point.x = m, end_point.y = n;
	return;
}

bool inside(int x, int y)
{
	if (x>=1 && x<=m && y>=1 && y<=n) return true;
	return false;
}

void bfs()
{
	queue<Point> q;
	q.push(start_point);
	memset(visit, 0, sizeof(visit));
	while (!q.empty())
	{
		Point point = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			Point tmp;
			tmp.x = point.x + dir[i][0];
			tmp.y = point.y + dir[i][1];
			tmp.k = point.k, tmp.steps = point.steps+1;
			if (tmp.x==end_point.x && tmp.y==end_point.y) { 
				cout << tmp.steps << endl; 
				return; 
			} if (matrix[tmp.x][tmp.y]) tmp.k--;  // meet obstacles, matrix[x][y] = 1
			else tmp.k = k;  // not obstacles, could meet another k obstacles
			if (inside(tmp.x,tmp.y) && !visit[tmp.x][tmp.y][tmp.k] && tmp.k>=0)
			{
				visit[tmp.x][tmp.y][tmp.k] = true;
				q.push(tmp);
			}
		}
	}
	cout << "-1" << endl;
	return;
}

int main()
{
	int T; cin >> T;
	while (T--)
	{
		init();
		bfs();
	}
	return 0;
}