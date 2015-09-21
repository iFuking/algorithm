/*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
*/
#include <iostream>
using namespace std;

// 8 direction: 
const int dir[][8] = {
	{-1,0}, {-1,1}, {0,1}, {1,1}, 
	{1,0}, {1,-1}, {0,-1}, {-1,-1}
};
const int maxn = 1010;
char matrix[maxn][maxn];
bool visit[maxn][maxn];  // if matrix[i][j] is visited
int m, n;

void dfs(int r, int c)
{
	for (int i = 0; i < 8; i++)
	{
		int row = r+dir[i][0];
		int col = c+dir[i][1];
		// find connected component
		if (row>=0 && row<m && col>=0 && col<n && matrix[row][col]=='@' && !visit[row][col]) 
		{
			visit[row][col] = true;
			dfs(row, col);
		}
	}
	return;
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		cin >> matrix[i];
	memset(visit, 0, sizeof(visit));
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j]=='@' && !visit[i][j]) 
			{
				cnt++;
				visit[i][j] = true;
				dfs(i, j);
			}
		}
	}
	cout << cnt << endl;
	return 0;
}