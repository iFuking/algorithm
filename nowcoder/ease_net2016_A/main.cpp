#include <iostream>
#include <cstdio>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0LL) return a;
    return gcd(b, a%b);
}

void solve() {
    int n; long long attack; cin >> n >> attack;
    for (int i = 0; i < n; ++i) {
        long long defence; scanf("%lld", &defence);
        if (attack >= defence) attack += defence;
        else attack += gcd(attack, defence);
    }
    cout << attack << endl;
    return;
}

int main()
{
    solve();
    return 0;
}
