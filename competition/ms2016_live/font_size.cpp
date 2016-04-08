#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 1e3 + 10;
int N, P, W, H;
int a[maxn];

void solve() {
    int tasks; cin >> tasks;
    while (tasks--) {
        scanf("%d %d %d %d", &N, &P, &W, &H);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &a[i]);
        }

        int left = 1, right = min(W, H);
        while (left <= right) {
            int mid = (left+right) >> 1;

            int col_chs = W/mid, rows_sum = 0;
            for (int i = 0; i < N; ++i) {
                int rows = ceil(1.0*a[i]/col_chs);
                rows_sum += rows;
            }

            int pages = ceil(1.0*rows_sum/(H/mid));

            if (pages <= P) left = mid+1;
            else right = mid-1;
        }
        printf("%d\n", right);
    }
    return;
}

int main() {
    solve();
    return 0;
}