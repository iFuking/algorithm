#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 501;
const int dir[][2] = {
	{-1, 0}, {1, 0}, {0, 1} 
};                     // up, down and right 
int n, m;              // rows and columns
int v[maxn][maxn];     // grid value
bool visit[maxn][maxn];  // if visited

void readin()
{
	cin >> n >> m;
	memset(v, 0, sizeof(v));  // clear v[][]

	// readin grid value
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> v[i][j];
	return;
}

void dfs(int row, int col)
{
	for (int i = 0; i < 3; i++)
	{
		int r = row + dir[i][0];
		int c = col + dir[i][1];

		if (r < 0) r = n-1;      // teleport to the bottom
		else if (r >= n) r = 0;  // teleport to the top

		if (c < m && !visit[r][c])
		{
			visit[r][c] = true;
			dfs(r, c);
		}
	}
	return;
}

void solve()
{
	for (int i = 0; i < n; i++) dfs(i, 0);
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