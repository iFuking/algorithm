#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> get_fac(int n) {
    vector<int> v;
    for (int i = 2; i <= sqrt(1.0*n); ++i) {
        if (n % i == 0) {
            v.push_back(i);
        }
    }

    int size = v.size();
    if (size < 1) {
        return v;
    }

    if (n == v[size-1]*v[size-1]) {
        --size;
    }
    for (int i = size-1; i >= 0; --i) {
        v.push_back(n/v[i]);
    }
    return v;
}

void solve() {
    // dp[i]表示在i位置需要最少的跳跃步数
    // for i factors fac[j]
    // dp[i+fac[j]] = min{dp[i+fac[j]], dp[i]+1};

    const int maxn = 0x3f3f3f3f;
    int n, m; cin >> n >> m;
    vector<int> dp(2*m, maxn);
    dp[n] = 0;
    for (int i = 4; i <= m; ++i) {
        vector<int> v = get_fac(i);
        for (int j = 0; j < v.size(); ++j) {
            dp[i+v[j]] = min(dp[i+v[j]], dp[i]+1);
        }
    }

    if (dp[m] == maxn) {
        cout << -1 << endl;
        return;
    }
    cout << dp[m] << endl;
    return;
}

int main() {
    solve();
    return 0;
}