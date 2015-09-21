#include <iostream>
#define MAXV 110
#define INF 1000010
#define Min(a, b) (a < b ? a : b)
using namespace std;

int dp[MAXV][MAXV];

int main(int argc, char *argv[])
{
	int V, E;
	cin >> V >> E;

	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			dp[i][j] = INF;
			if (i == j) dp[i][j] = 0;		 
		}
	}	

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		
		if (w > dp[u][v]) continue;
		else dp[u][v] = dp[v][u] = w;
	}

	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++)
			for (int j = 1; j <= V; j++)
				dp[j][i] = dp[i][j] = Min(dp[i][j], dp[i][k]+dp[k][j]);

	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	return 0;
}