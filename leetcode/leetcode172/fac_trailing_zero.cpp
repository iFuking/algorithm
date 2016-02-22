#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt_five = 0;
        for (int i = 1; i <= log(1.0*n)/log(5.0); ++i) cnt_five += n/pow(5.0, i);
        return cnt_five;
    }
};

int main()
{
    Solution sol;
    while (true) {
        int n; cin >> n;
        cout << sol.trailingZeroes(n) << endl;
    }
    return 0;
}
