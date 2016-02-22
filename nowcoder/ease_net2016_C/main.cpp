#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 21;
int graph[maxn][maxn];
int N, M, K;

const int dir[][2] = {
    {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
    {1, 0}, {1, -1}, {0, -1}, {-1, -1},
    {0, 0}
};

int cover_nums(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < sizeof(dir)/sizeof(dir[0]); ++i) {
        int dx = x+dir[i][0], dy = y+dir[i][1];
        if (dx>=1 && dx<=N && dy>=1 && dy<=M) cnt += graph[dx][dy];
    }
    return cnt;
}

void clear_section(int x, int y) {
    for (int i = 0; i < sizeof(dir)/sizeof(dir[0]); ++i) {
        int dx = x+dir[i][0], dy = y+dir[i][1];
        if (dx>=1 && dx<=N && dy>=1 && dy<=M) graph[dx][dy] = 0;
    }
    return;
}

void solve() {
    cin >> N >> M >> K;
    for (int i = 0; i < K; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        ++graph[x][y];
    }

    int max_cnt = -1, px, py;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            int cnt = cover_nums(i, j);
            if (cnt > max_cnt) {
                max_cnt = cnt;
                px = i; py = j;
            }
        }
    }
    clear_section(px, py);

    int ans = max_cnt; max_cnt = -1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            int cnt = cover_nums(i, j);
            if (cnt > max_cnt) max_cnt = cnt;
        }
    }
    ans += max_cnt;
    cout << ans << endl;
    return;
}

int main()
{
    solve();
    return 0;
}
