#include <iostream>
using namespace std;

class Solution {
public:
    long long labs(long long n) {
        return n > 0 ? n : 0-n;
    }

    int reverse(int x) {
        long long x_copy = x;
        bool signal = false;
        if (x_copy < 0) signal = true;
        x_copy = labs(x_copy);

        long long rev = 0;
        while (x_copy) {
            rev = 10*rev + x_copy%10;
            x_copy /= 10;
        }
        rev = signal?0-rev:rev;
        if (rev<-0x80000000LL || rev>0x7fffffffLL) return 0;
        return rev;
    }
};

int main()
{
    Solution sol;
    while (true) {
        // cout << 0x7fffffff << " " << 0x80000000 << endl;
        int x; cin >> x;
        cout << sol.reverse(x) << endl;
    }
    return 0;
}
