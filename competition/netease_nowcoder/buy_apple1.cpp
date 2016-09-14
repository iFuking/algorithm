#include <iostream>
#include <vector>
using namespace std;

void solve() {
    // dp[i]表示购买i各苹果最少需要购买的袋数
    // dp[i] = min{dp[i-6]+1, dp[i-8]+1};

    int n; cin >> n;
    vector<int> dp(n+1, -1);
    dp[6] = 1; dp[8] = 1;
    for (int i = 9; i <= n; ++i) {
        if (dp[i-6]!=-1 && dp[i-8]!=-1) {
            dp[i] = min(dp[i-6], dp[i-8])+1;
            continue;
        }

        if (dp[i-6] != -1) {
            dp[i] = dp[i-6]+1;
        }
        if (dp[i-8] != -1) {
            dp[i] = dp[i-8]+1;
        }
    }

    cout << dp[n] << endl;
    return;
}

int main() {
    solve();
    return 0;
}