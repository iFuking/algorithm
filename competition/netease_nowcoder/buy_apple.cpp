#include <iostream>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n & 1) {
        cout << -1 << endl;
        return;
    }

    n /= 2;
    int min_package = 0x7fffffff;
    for (int i = 0; i <= n/3; ++i) {
        for (int j = 0; j <= n/4; ++j) {
            if (3*i+4*j == n) {
                min_package = min(min_package, i+j);
            }
        }
    }

    if (min_package < 0x7fffffff) {
        cout << min_package << endl;
        return;
    }
    cout << -1 << endl;
    return;
}

int main() {
    solve();
    return 0;
}