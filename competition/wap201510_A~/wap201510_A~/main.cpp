#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 505;
int grid[maxn][maxn];
int m, n;
long long down[maxn], up[maxn];
long long dp[maxn];

inline long long max(long long x, long long y) { return x>y ? x : y; }

void move(int col, long long score[], int dir)
{
	int start_row;
	if (dir == 1) start_row = 0;  // go down
	else start_row = m-1;         // go up

	int tele_start = -1;
	long long tele_score = -1;

	if (grid[start_row][col] == -1) score[start_row] = -1;  // blocked
	else if (dp[start_row] != -1) score[start_row] = dp[start_row]+grid[start_row][col];  // left not blocked
	else {  // left blocked
		for (int i = m-1-start_row; i != start_row; i -= dir) {
			if (grid[i][col] == -1) break;  // not teltport
			if (dp[i] != -1) { tele_start = i; break; }  // teleport position
		}
		score[start_row] = (tele_start==-1) ? -1 : grid[start_row][col];
	}

	for (int i = start_row+dir; i != m-1-start_row+dir; i += dir) {
		if (grid[i][col]==-1 || (score[i-dir]==-1 && dp[i]==-1)) {  // blocked both this cell and previous
			score[i] = -1; continue;
		}
		if (dp[i] > score[i-dir]) {  // score from left
			tele_score = tele_start = -1;
			score[i] = dp[i]+grid[i][col];
			continue;
		}

		// score from down or up
		if (tele_start == -1) score[i] = score[i-dir]+grid[i][col];
		else {
			long long tele_pre = max(tele_score, dp[i]);
			if (tele_start == i) {
				tele_score = tele_start = -1;
				score[i] = (tele_pre==-1) ? -1 : tele_pre+grid[i][col];
			} else {
				score[i] = score[i-dir]+grid[i][col];
				tele_score = (tele_pre==-1) ? -1 : tele_pre+grid[i][col];
			}
		}
	}
	return;
}

void downward(int col) { move(col, down, 1); return; }
void upward(int col) { move(col, up, -1); return; }

long long snake_game()
{
	for (int j = 0; j < n; ++j) {
		downward(j);  // go up
		upward(j);    // go down, enum for each column, find the highest score
		// compare and store the highest score of each cell
		for (int i = 0; i < m; ++i) dp[i] = max(down[i], up[i]);
	}

	long long ans = -1;
	for (int i = 0; i < m; ++i) ans = max(ans, dp[i]);
	return ans;
}

void solve()
{
	scanf("%d %d", &m, &n);
    for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) scanf("%d", &grid[i][j]);
	}
	/*FILE *fp = NULL;
	fp = fopen("../../wap201510/ex1_testcase.txt", "r");
	fscanf(fp, "%d %d", &m, &n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) fscanf(fp, "%d", &grid[i][j]);
	}
	fclose(fp);*/
	cout << snake_game() << endl;
	return;
}

int main()
{
	solve();
	return 0;
}


/*
4 4
-1 4 5 1
2 -1 2 4
3 3 -1 3
4 2 1 2

4 4
-1 4 5 1
2 -1 2 4
3 3 -1 -1
4 2 1 2
*/