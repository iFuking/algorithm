#include <iostream>
using namespace std;

long long F(int n) {
    if (n == 1) return 1LL;
    int sig = n&1LL;
    return F(n/2)+1LL*(n+sig)*(n+sig)/4;
}

void solve() {
    int n; cin >> n;
    cout << F(n) << endl;
    return;
}

int main() {
    solve();
    return 0;
}