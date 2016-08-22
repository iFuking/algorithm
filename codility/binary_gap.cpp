#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 32;

string int2binary(int N) {
    string s;
    while (N) {
        s += ((N&1) + '0');
        N >>= 1;
    }
    return s;
}

int solution(int N) {
    // write your code in C++11 (g++ 4.8.2)
    string s = int2binary(N);

    int gap = 0;
    int idx_zero = -1, idx_one = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0') {
            if (idx_one >= 0) {
                idx_zero = i;
            }
        } else {
            if (idx_zero>=0 && idx_one>=0) {
                gap = max(gap, i-idx_one-1);
                idx_zero = -1;
                idx_one = i;
            }
            
            idx_one = idx_zero==-1 ? i : idx_one;
        }
    }
    return gap;
}

int main() {
    int a[] = {-1, 3, -4, 5, 1, -6, 2, 1};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    
    while (true) {
        int n; cin >> n;
        cout << solution(n) << endl;
    }
    return 0;
}