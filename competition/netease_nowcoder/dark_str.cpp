#include <iostream>
#include <vector>
using namespace std;

void solve() {
    // dp1[i]表示结尾两个字符相同的长度为i的暗黑字符串的个数
    // .*XX
    // 增加一个字符后字符串：
    // .*XXX
    // .*XXY
    // .*XXZ

    // dp2[i]表示结尾两个字符不同的长度为i的暗黑字符串的个数
    // .*XY
    // 增加一个字符后字符串：
    // .*XYX
    // .*XYY

    // dp1[i] = dp1[i-1]+dp2[i-1]
    // dp2[i] = 2*dp1[i-1]+dp2[i-1]

    int n; cin >> n;
    if (n == 1) {
        cout << 3 << endl;
        return;
    }
    if (n == 2) {
        cout << 9 << endl;
        return;
    }

    vector<long long> dp1(n+1, 0LL);
    vector<long long> dp2(n+1, 0LL);

    dp1[2] = 3LL;
    dp2[2] = 6LL;
    for (int i = 3; i <= n; ++i) {
        dp1[i] = dp1[i-1]+dp2[i-1];
        dp2[i] = 2*dp1[i-1]+dp2[i-1];
    }
    cout << dp1[n]+dp2[n] << endl;
    return;
}

int main() {
    solve();
    return 0;
}