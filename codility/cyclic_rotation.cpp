#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++11 (g++ 4.8.2)
    int n = A.size();
    if (n == 0) return A;
    K %= n;
    if (K == 0) return A;

    vector<bool> v(n, false);

    int idx_old = 0, idx_new = (idx_old+K)%n;
    int last = A[0];
    for (int i = 0; i < n; ++i) {
        int idx_old = i, idx_new = (idx_old+K)%n;
        int last = A[i];

        v[idx_old] = true;
        while (!v[idx_new]) {
            int tmp = A[idx_new];
            A[idx_new] = last;
            last = tmp;

            v[idx_new] = true;
            idx_old = idx_new;
            idx_new = (idx_old+K)%n;
        }
        A[i] = last;
    }
    return A;
}

int main() {
    int a[] = {-1, -2, -3, -4, -5, -6};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    
    while (true) {
        int n; cin >> n;
        vector<int> v1 = solution(v, n);
        for (int i = 0; i < v1.size(); ++i) {
            cout << v1[i] << ",";
        }
    }
    return 0;
}