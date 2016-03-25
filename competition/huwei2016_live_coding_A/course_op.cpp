#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 3e4 + 10;
int score[maxn];

void solve() {
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &score[i]);
    }

    for (int i = 0; i < M; ++i) {
        char op; int index, n;
        getchar();
        scanf("%c %d %d", &op, &index, &n);

        if (op == 'Q') {
            int max_score = 0;
            for (int j = index; j <= n; ++j) {
                if (score[j] > max_score) {
                    max_score = score[j];
                }
            }
            printf("%d\n", max_score);
            continue;
        }

        score[index] = n;
    }
    return;
}

int main() {
    solve();
    return 0;
}
