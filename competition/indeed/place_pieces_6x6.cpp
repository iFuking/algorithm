#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int maxn = 6;
int row[maxn], col[maxn];
bool visit[maxn][maxn];

bool is_continue() {
    for (int i = 0; i < maxn; ++i) {
        if (row[i] < 0) return false;
        if (col[i] < 0) return false;
    }
    return true;
}

bool is_valid() {
    for (int i = 0; i < maxn; ++i) {
        if (row[i] != 0) return false;
        if (col[i] != 0) return false;
    }
    return true;
}

// 0 <= pos < maxn*maxn
// row: pos/maxn
// col: pos%maxn
void dfs(int pos, int &ans) {
    if (pos == maxn*maxn) {
        // each row and column has three pieces
        if (!is_valid()) return;
        ++ans;
        return;
    }

    // previous rows must have meet the condition
    // if not, no need to backtrace
    for (int i = 0; i < pos/maxn; ++i) {
        if (row[i] != 0) return;
    }

    // this position is '.', and satisfied row and column
    if (!visit[pos/maxn][pos%maxn] && row[pos/maxn]>0 && col[pos%maxn]>0) {
        // place a piece
        --row[pos/maxn]; --col[pos%maxn];
        dfs(pos+1, ans);
        ++row[pos/maxn]; ++col[pos%maxn];

        // do not place
        dfs(pos+1, ans);
        return;
    }
    
    // ignore this position
    dfs(pos+1, ans);
    return;
}

void solve() {
    for (int i = 0; i < maxn; ++i) {
        row[i] = col[i] = 3;
    }

    char table[maxn][maxn];
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            scanf("%c", &table[i][j]);
            if (table[i][j] == 'o') {
                visit[i][j] = true;
                --row[i]; --col[j];
            }
        }
        getchar();
    }

    if (!is_continue()) {
        cout << 0 << endl;
        return;
    }

    int ans = 0; dfs(0, ans);
    cout << ans << endl;
    return;
}

int main() {
    solve();
    return 0;
}