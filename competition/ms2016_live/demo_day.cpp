#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

const int maxn = 1e2 + 10;
const int INF = 0x3f3f3f3f;

int board[maxn][maxn][2];
int graph[maxn][maxn];
int ans;
int N, M;

void dfs(int row, int col, int num, int dir) {
    if (row == N-1) {
        for (int i = col; i < M; i++) num += graph[N-1][i];
        if (ans > num) ans = num;
        return;
    }
    if (col == M-1) {
        for (int i = row; i < N; i++) num += graph[i][M-1];
        if (ans > num) ans = num;
        return;
    }

    num += graph[row][col];
    if (num >= ans) return;
    if (num >= board[row][col][dir]) return;
    else board[row][col][dir] = num;

    if (dir == 0) {
        dfs(row, col+1, num, 0);
        if (graph[row][col+1]) dfs(row+1, col, num, 1);
        else dfs(row+1, col, num+1, 1);
    } else {
        dfs(row+1, col, num, 1);
        if (graph[row+1][col]) dfs(row, col+1, num, 0);
        else dfs(row, col+1, num+1, 0);
    }
}

void solve() {
    while (scanf("%d %d", &N, &M) != EOF) {
        char line[maxn];
        for (int i = 0; i < N; ++i) {
            scanf("%s", line);
            for (int j = 0; j < M; ++j) {
                if (line[j] == '.') graph[i][j] = 0;
                else graph[i][j] = 1;
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                board[i][j][0] = board[i][j][1] = INF;
            }
        }
        ans = 0;
        for (int i = 0; i < M; ++i) ans += graph[0][i];
        for (int i = 1; i < N; ++i) ans += graph[i][M-1];
        dfs(0, 0, 0, 0);
        printf("%d\n", ans);
    }
    return;
}

int main() {
    solve();
    return 0;
}
