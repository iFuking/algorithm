#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long ll_abs(long long x) {
        return x>0 ? x : -x;
    }

    double myPow(double x, int n) {
        bool flag = false;
        if (n < 0) flag = true;
        long long n_copy = ll_abs(n);

        double my_pow = 1.0, base = x;
        while (n_copy) {
            if (n_copy&1) my_pow *= base;
            base *= base; n_copy >>= 1;
        }

        return !flag ? my_pow : 1.0/my_pow;
    }
};

int main()
{
    Solution sol;
    while (true) {
        double x; int n; cin >> x >> n;
        cout << sol.myPow(x, n) << endl;
    }
    return 0;
}
