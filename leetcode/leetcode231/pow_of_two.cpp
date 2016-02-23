#include <iostream>
#include <cmath>
using namespace std;

const double esp = 1e-12;

class Solution {
public:
    double d_abs(double x) {
        return x > 0 ? x : -x;
    }

    bool isPowerOfTwo(int n) {
        double p = log(1.0*n)/log(3.0);
        int int_p = p+0.5;
        return d_abs(p-int_p) < esp;
    }
};

//class Solution {
//public:
//    bool isPowerOfTwo(int n) {
//        if (n < 1) return false;
//
//        bool high_one = false;
//        while (n) {
//            if (n&1) {
//                if (high_one) return false;
//                high_one = true;
//            }
//            n >>= 1;
//        }
//        return true;
//    }
//};

int main() {
    Solution sol;
    while (true) {
        int n; cin >> n;
        cout << sol.isPowerOfTwo(n) << endl;
    }
    return 0;
}
