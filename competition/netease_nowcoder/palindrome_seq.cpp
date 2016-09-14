#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    int left = 0, right = n-1;
    int step = 0;
    while (left < right) {
        if (v[left] < v[right]) {
            v[left+1] += v[left];
            ++left; ++step;
        } else if (v[left] > v[right]) {
            v[right-1] += v[right];
            --right; ++step;
        } else {
            ++left; --right;
        }
    }
    cout << step << endl;
    return;
}

int main() {
    solve();
    return 0;
}